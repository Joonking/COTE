#include <iostream>
#include <string>
#include <set>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	set<string> StrSet;

	for (int i = 0; i < str.size(); i++)
	{
		StrSet.insert(str.substr(i));
	}

	for (string s : StrSet)
		cout << s << "\n";


	return 0;
}