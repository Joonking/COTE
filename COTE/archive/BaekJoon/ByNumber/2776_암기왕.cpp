#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int N, M;
		cin >> N;

		unordered_set<int> Su1;

		for (int i = 0; i < N; i++)
		{
			int Temp;
			cin >> Temp;
			Su1.insert(Temp);
		}
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int Temp;
			cin >> Temp;
			if (Su1.find(Temp) == Su1.end())
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
	}

	return 0;
}