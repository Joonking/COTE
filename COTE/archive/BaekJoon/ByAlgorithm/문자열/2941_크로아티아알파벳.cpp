#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int sum = 0;

	for (int i = s.size()-1; i >= 0 ; i--)
	{
		if (s[i] == '=' && i > 1)
		{
			if (s[i - 1] == 'z' && s[i - 2] == 'd')
			{
				sum++;
				i -= 2;
				continue;
			}
		}

		if (s[i] == '=' && i>0)
		{
			if (s[i - 1] == 'c' || s[i - 1] == 's' || s[i - 1] == 'z')
			{
				sum++;
				i--;
				continue;
			}
		}

		if (s[i] == '-' && i > 0)
		{
			if (s[i - 1] == 'c' || s[i - 1] == 'd')
			{
				sum++;
				i--;
				continue;
			}
		}

		if (s[i] == 'j' && i > 0)
		{
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
			{
				sum++;
				i--;
				continue;
			}
		}

		sum++;
	}

	cout << sum;
}