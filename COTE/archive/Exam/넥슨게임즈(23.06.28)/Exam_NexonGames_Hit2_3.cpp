/*
3. Programming Contest

A programming organization is planning a contest for several programmers, each of which has a certain rating.
(The higher the rating, the better the programmer.) Each programmer is paired with another programmer, 
and the difference between their ratings is referred to as the "bias amount". Given the ratings of all the programmers in the
contest, what is the minimum total bias amount that can be achieved by optimally planning the programmer pairs?

Example
n = 4
raings = [4, 2, 5, 1]

The optimal solution is:
Pair the second Programmer (2) with the fourth (1) for a difference of 1.
Pair the first programmer (4) with the third (5) for a difference of 1.
This results in a total bias amount of 1 + 1 =2.

Function Descroption
Complete the function minimizeBias in the editor below.

minimizeBias has the following parameter:
	int ratings[n] : the ratings of each of the programmers.
	Returns:
		int: the minimum total bias amount that can be achieved in the contest

Constraints
	*	1 <= n <= 100000
	*	1 <= ratings[i] <= 1000000000
	*	n is even

Input Format For Custom Testing
The first line contains an integer, n, the number of elements in ratings.
Each line i of the n subsequent lines (where 0 <= i < n) contains an integer, ratings[i].

Sample Case 0
STDIN			Function
------------------------------
4			->		ratings[] size n = 4
1			->		ratings = [1, 3, 6, 6]
3
6
6

Sample Output 0
2

Explannation
The Oprimal solution is to pair the first programmer (1) with the second (3) for a difference of 2,
and the third programmer (6) with fourth (6) for a difference of 0. 
This results in a total bias amount of 2.


Sample Case 1
STDIN			Function
------------------------------
6			->		ratings[] size n = 6
2			->		ratings = [2, 4, 5, 3, 7, 8]
4
5
3
7
8

Sample Output 1
3

Explannation
The optimal solution is to assign the following pairs: (2,3), (4,5), and (7,8).
This results in the least total bias amount, which is 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

	sort(V.begin(), V.end());
	int sum = 0;
	for (int i = 0; i < V.size() - 1; i += 2)
	{
		sum += (V[i + 1] - V[i]);
	}
	cout << sum;
}