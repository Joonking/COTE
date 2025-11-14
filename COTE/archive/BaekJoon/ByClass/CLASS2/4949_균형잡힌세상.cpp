#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		string str;
		getline(cin, str);

		if (str == ".") break;

		stack<char> ST;
		bool flag = false;
		for (char ch : str)
		{
			if (ch == '(' || ch=='[')
			{
				ST.push(ch);
			}
			
			if (ch == ')')
			{
				if (ST.empty() == false && ST.top() == '(')
					ST.pop();
				else {
					flag = true;
					break;
				}
			}
			if (ch == ']')
			{
				if (ST.empty() == false && ST.top() == '[')
					ST.pop();
				else
				{
					flag = true;
					break;
				}
			}
		}
		if (ST.empty() && flag == false)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}


}