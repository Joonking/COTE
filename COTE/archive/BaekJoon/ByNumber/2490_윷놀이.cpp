#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 3; i++)
	{
		int Count = 0;
		for (int k = 0; k < 4; k++)
		{
			int a;
			cin >> a;
			if (a==0)
				Count++;
		}
		switch (Count)
		{
		case 0:
			cout << "E" << endl;
			break;
		case 1:
			cout << "A" << endl;
			break;
		case 2:
			cout << "B" << endl;
			break;
		case 3:
			cout << "C" << endl;
			break;
		case 4:
			cout << "D" << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}