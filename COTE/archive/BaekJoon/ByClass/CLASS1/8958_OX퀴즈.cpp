#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TestCaseNum;
	cin >> TestCaseNum;

	for (int i = 0; i < TestCaseNum; i++)
	{
		string TestCase;
		cin >> TestCase;

		int Combo = 0, Score = 0;
		for (char C : TestCase)
		{
			if (C == 'O')
			{
				Combo++;
			}
			else if (C == 'X')
			{
				Combo = 0;
			}
			Score += Combo;
		}
		cout << Score << endl;
	}

	return 0;
}