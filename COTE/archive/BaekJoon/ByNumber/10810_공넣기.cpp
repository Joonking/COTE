#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int baguni[101] = { 0 };

	for (int t = 0; t < M; t++)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int p = i; p <= j; p++)
		{
			baguni[p] = k;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << baguni[i] << " ";
	}

}