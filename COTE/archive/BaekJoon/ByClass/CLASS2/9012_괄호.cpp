#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		stack<char> ST;
		string tempStr;
		cin >> tempStr;
		if (tempStr[0] == ')')
		{
			cout << "NO" << endl;
			continue;
		}

		ST.push(tempStr[0]);
		for (int i = 1; i < tempStr.size(); i++)
		{
			if (tempStr[i] == ')')
			{
				if (!ST.empty()) {
					if (ST.top() == '(')
					{
						ST.pop();
					}
				}
				else
				{
					ST.push(tempStr[i]);
				}
			}
			else
			{
				ST.push(tempStr[i]);
			}
		}

		if (ST.empty())
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}



}