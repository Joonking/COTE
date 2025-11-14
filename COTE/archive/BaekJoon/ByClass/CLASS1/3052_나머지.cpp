#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio;
	cin.tie(0);

	int t, M[42]={0}, count = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> t;
		M[t%42]++;
	}

	for (int i = 0; i < 42; i++)
		if (M[i]) count++;

	cout << count;
}