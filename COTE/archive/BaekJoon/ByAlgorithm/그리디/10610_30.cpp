#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//30의 배수
// 1. 끝자리가 0이어야함.
// 2. 모든 자리 수의 합이 3의 배수여야함. 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string N;
	cin >> N;

	bool IsInZero = false;
	long JariSum = 0;

	priority_queue<char> PQ;

	for (char c : N)
	{
		if (c == '0') IsInZero = true;
		JariSum += c - '0';
		PQ.push(c);
	}

	if (JariSum % 3 == 0 && IsInZero)
	{
		while (PQ.empty() == false)
		{
			cout << PQ.top();
			PQ.pop();
		}
	}
	else
		cout << -1 << "\n";


	return 0;
}