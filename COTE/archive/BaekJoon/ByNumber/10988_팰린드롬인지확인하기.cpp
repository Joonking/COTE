#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			cout << 0 << endl;
			return 0;
		}
	}

	cout << 1 << endl;
	return 0;

}