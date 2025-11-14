#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	int alphapat[26] = { 0 };

	for (char c : s)
	{
		alphapat[c - 'a']++;
	}

	for (int i : alphapat)
	{
		cout << i << " ";
	}
}
