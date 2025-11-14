#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;

	while (getline(cin, str))
	{
		cout << str << "\n";
	}

	return 0;
}