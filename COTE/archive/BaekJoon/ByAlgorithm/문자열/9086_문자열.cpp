#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;
		cout << str[0] << str[str.size() - 1] << "\n";
	}

}