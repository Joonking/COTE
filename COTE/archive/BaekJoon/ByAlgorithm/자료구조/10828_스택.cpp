#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<int> ST;

	for (int i = 0; i < N; i++)
	{
		string tempStr;
		cin >> tempStr;

		if (tempStr == "push")
		{
			int temp;
			cin >> temp;
			ST.push(temp);
		}
		if (tempStr == "pop")
		{
			if (ST.empty())
				cout << -1 << endl;
			else
			{
				cout << ST.top() << endl;
				ST.pop();
			}
			
		}
		if (tempStr == "size")
		{
			cout << ST.size() << endl;
		}
		if (tempStr == "empty")
		{
			cout << ST.empty() << endl;
		}
		if (tempStr == "top")
		{
			if (ST.empty())
				cout << -1 << endl;
			else
			{
				cout << ST.top() << endl;
			}
		}

	}

}