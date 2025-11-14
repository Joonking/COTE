#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S;
	cin >> S;

	int Count0To1 = 0;
	int Count1To0 = 0;

	bool IsContinue = false;

	// 0 -> 1
	for (char c : S)
	{
		if (c == '0')
		{
			if (IsContinue)
				continue;
			else
			{
				IsContinue = true;
				Count0To1++;
			}
		}
		if (c == '1')
		{
			if (IsContinue) IsContinue = false;
		}
	}

	IsContinue = false;

	// 1 -> 0
	for (char c : S)
	{
		if (c == '1')
		{
			if (IsContinue)
				continue;
			else
			{
				IsContinue = true;
				Count1To0++;
			}
		}
		if (c == '0')
		{
			if (IsContinue) IsContinue = false;
		}
	}

	if (Count0To1 <= Count1To0)
		cout << Count0To1 << "\n";
	else
		cout << Count1To0 << "\n";

	return 0;
}