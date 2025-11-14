#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, sum = 0, Alpha[26] = { 0 };
	string s;
	cin >> N;
	bool Y = false;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j=0; j<s.size();j++)
		{
			if (j != 0)
			{
				if (s[j] == s[j - 1] && j != 0)
					Y = true;
				else
					Y = false;
			}
		
			if (!Y)
			{
				if (Alpha[s[j] - 97] != 0)
					break;
				Alpha[s[j] - 97]++;
			}
			if (j == s.size() - 1)
				sum++;
		}
		Y = false;
		s.clear();
		for (int k = 0; k < 26; k++)
			Alpha[k] = 0;
	}

	cout << sum;

}