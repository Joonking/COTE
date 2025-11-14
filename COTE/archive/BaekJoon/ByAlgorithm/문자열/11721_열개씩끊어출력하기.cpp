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

	for (int i = 1; i <= str.size(); i++)
	{
		cout << str[i-1];
		if (i % 10 == 0)
			cout << endl;
	}



}