#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> MyStack;

	int N;
	cin >> N;

	while (N--)
	{
		int Temp;
		cin >> Temp;
		MyStack.push(Temp);
	}

	int Count = 0;
	int Max = -1;
	while (MyStack.empty() == false)
	{
		int Top = MyStack.top();
		MyStack.pop();

		if (Top > Max)
		{
			Max = Top;
			Count++;
		}
	}

	cout << Count;

	return 0;
}