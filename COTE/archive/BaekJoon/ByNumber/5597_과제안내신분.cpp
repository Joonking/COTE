#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);

	int M[30] = { 0 }, t;

	for (int i =0; i < 30; i++)
	{
		cin >> t;
		M[t - 1] = 1;
	}

	for (int i = 0; i < 30; i++)
	{
		if (M[i] == 0)
			cout << i + 1 << "\n";
	}
}