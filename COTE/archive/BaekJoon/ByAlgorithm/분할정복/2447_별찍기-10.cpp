#include<iostream>
using namespace std;

void Sqaure(int x, int y, int n) {

	if ((x/n)%3 == 1 && (y/n)%3 == 1)
	{
		cout << " ";
	}
	else
	{
		if (n / 3 == 0)
			cout << "*";
		else
			Sqaure(x, y, n/3);
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			Sqaure(i, k, N);
		}
		cout << "\n";
	}
}

