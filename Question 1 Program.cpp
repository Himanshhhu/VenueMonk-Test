#include <iostream>
using namespace std;
const unsigned int Sunday = 1;
// based on Zeller's congruence
// January = 1, February = 2, ..., December = 12
// returns 0 => Saturday, 1 => Sunday, 2 => Monday, ... 6 => Friday
unsigned int getWeekday(int year, int month, int day)
{

  // January and February are counted as month 13 and 14 of the previous year
  if (month <= 2)
  {
    month += 12;
    year--;
  }
  return (day +
          13 * (month + 1) / 5 +
          year + year / 4 - year / 100 + year / 400)
         % 7;
}

int main()
{

    int year1=1901,year2=2000, month1=1, month2=12, day1=1, day2=31;

    // jumping forward to the first day of the month
    int currentYear  = year1;
    int currentMonth = month1;
    if (day1 > 1)
    {
      currentMonth++;

      // from December to January of next year
      if (currentMonth > 12)
      {
        currentMonth -= 12;
        currentYear++;
      }
    }

    // number of relevant Sundays
    int sum = 0;

    // same patterns every 2800 years
    while (currentYear + 2800 < year2)
    {
      currentYear += 2800;
      sum += 4816;         // there are 4816 Sundays on the first of //a month in 2800 years
    }

    // simple scanning through all months
    while (currentMonth < month2 || currentYear < year2)
    {
      // counting Sundays
      if (getWeekday(currentYear, currentMonth, 1) == Sunday)
        sum++;

      currentMonth++;

      // from December to January of next year
      if (currentMonth > 12)
      {
        currentMonth -= 12;
        currentYear++;
      }
    }
    // checking last month, too
    if (getWeekday(currentYear, currentMonth, 1) == Sunday)
      sum++;

    cout << sum ;

  return 0;
}
