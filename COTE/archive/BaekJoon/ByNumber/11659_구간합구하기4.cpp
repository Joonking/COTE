#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//N : 수의 개수, M : 합을 구해야 하는 횟수
	int N, M;
	cin >> N >> M;

	int S[100001] = { 0 };		//합이 들어갈 배열

	//N개의 수가 주어짐.
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	//합을 구해야 하는 구간이 주어짐.
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << S[b] - S[a - 1] << "\n";
	}
}