#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> Ai(N + 1);		//털 주기
	vector<int> Dogs(N + 1, 0);  //개 털
	vector<int> Bi(M + 1);		//누구 자를지

	for (int i = 1; i <= N; i++)
	{
		cin >> Ai[i];
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> Bi[i];
	}

	for (int i = 1; i <= M+1; i++)
	{
		for (int k = 1; k <= N; k++)
		{
			if (Dogs[k] == -2)
				Dogs[k] = -1;
			else if (Dogs[k] == -1)
				Dogs[k] = -1;
			else
				Dogs[k]++;

			if (Dogs[k] > Ai[k])
				Dogs[k] = -1; //엉킴
		}

		if (i == M + 1) 
			break;

		//빗질 할 강아지
		int BitDog = Bi[i];

		if (Dogs[BitDog] == -1)
			Dogs[BitDog] = -2;
		else if (Dogs[BitDog] == -2)
			Dogs[BitDog] = 0;
		else
			Dogs[BitDog] = 0;
	}
	int Count = 0;
	for (int i = 1; i <= N; i++)
	{
		if (Dogs[i] < 0)
		{
			cout << i << endl;
			Count++;
		}
			
	}

	cout << Count;

	return 0;
}