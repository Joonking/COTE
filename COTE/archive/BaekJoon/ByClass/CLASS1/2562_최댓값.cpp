#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, Max = 0, A;

	for (int i = 1; i <= 9; i++)
	{
		cin >> t;
		if (t > Max)
		{
			Max = t;
			A = i;
		}
	}
	cout << Max << "\n";
	cout << A;
}