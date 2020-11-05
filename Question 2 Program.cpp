#include<iostream>
using namespace std;

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count( int S[], int m, int n )
{
	// base case
	if (n == 0)
		return 1;

	// If n is less than 0 then no
	// solution exists
	if (n < 0)
		return 0;

	// If there are no coins and n
	// is greater than 0, then no
	// solution exist
	if (m <=0 && n >= 1)
		return 0;

	// count is sum of solutions (i)
	// including S[m-1] (ii) excluding S[m-1]
	return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

int main()
{
	int arr[] = {10, 20, 50, 100, 200, 500, 1000,2000};
	int size = 8;
	int sum=2000;
	cout<<count(arr, size, sum);
	return 0;
}
