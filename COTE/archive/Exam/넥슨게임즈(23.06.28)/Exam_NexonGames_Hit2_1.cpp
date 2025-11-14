/*
1. Sum Them All

Calculate the sum of an array of integers.

Example
numbers = [3, 13, 4, 11, 9]

The sum is 3 + 13 + 4 + 11 + 9 = 40

Function Description
Complete the function arraySum in the editor below

arraySum has the following parameters(s):
	int numbers[n]: an array of integers
	Returns
		int: integer sum of the numbers array

Constraints
	*	1 <= n <= 10000
	*	1 <= numbers[i] <= 10000

InputFormat for Custom Testing
input from stdin will be processed as follows and passed to the function.
the first line contains an integer n, the size of the array numbers.
Each of the next n lines contains an integer numbers[i] where 0 <= i < n.

Sample Case 0
STDIN			Function
-----------------------------
5			->		numbers[] size n = 5
1			->		numbers = [1,2,3,4,5]
2
3
4
5

Sample Output0
15

Explanation 0
1 + 2 + 3 + 4 + 5 =15.

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> V(N);
	for (int i = 0; i < N; i++)
	{
		cin >> V[i];
	}

	int sum = 0;
	for (int i : V)
	{
		sum += i;
	}
	cout << sum;
}