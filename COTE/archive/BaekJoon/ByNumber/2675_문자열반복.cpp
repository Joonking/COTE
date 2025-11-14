#include <iostream>
#include <string>
using namespace std;

int main()
{
	int C, R;
	string S;

	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> R;
		cin >> S;
		for (char c : S)
		{
			for (int j = 0; j < R; j++)
			{
				cout << c;
			}
		}
		cout << endl;
	}
}