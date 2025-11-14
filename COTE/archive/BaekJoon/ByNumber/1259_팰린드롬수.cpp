#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		string StrTemp, StrReverse;
		cin >> StrTemp;
		if (StrTemp == "0")
			break;
		StrReverse = StrTemp;
		reverse(StrReverse.begin(), StrReverse.end());
		if (StrTemp == StrReverse)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}