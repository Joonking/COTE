#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*b = *a;
	*a = temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int baguni[101] = { 0 };

	for (int i=1;i<=N;i++)
	{
		baguni[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		swap(baguni[a], baguni[b]);
	}
	
	for (int i = 1; i <= N; i++)
		cout << baguni[i] << " ";
}