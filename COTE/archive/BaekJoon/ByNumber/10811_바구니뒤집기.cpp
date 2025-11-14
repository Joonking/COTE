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

	for (int i = 1; i <= N; i++)
		baguni[i] = i;

	for (int t = 0; t < M; t++)
	{
		int i, j;
		cin >> i >> j;

		for (int p = i; p <j;p++)
		{
			if (p > (j + i )/ 2) break;
			int temp = baguni[p];
			baguni[p] = baguni[j - p + i];
			baguni[j - p + i] = temp;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << baguni[i] << " ";
	}

}