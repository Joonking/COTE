#include <iostream>
using namespace std;

int main()
{
	int N, C = 0, A, B = 0;
	cin >> N;

	A = N / 5;

	while (A)
	{
		if ((N - (A * 5)) % 3 == 0)
		{
			B = (N - (A * 5)) / 3;
			cout << A + B;
			return 0;
		}
		A--;
	}

	if (N % 3 != 0)
		cout << -1;
	else
		cout << N / 3;

	return 0;
}