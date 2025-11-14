#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		
		vector<pair<int, int>> People(N);
		for (int k = 0; k < N; k++)
		{
			cin >> People[k].first;
			cin >> People[k].second;
		}
		
		sort(People.begin(), People.end());
		int	Ranking = INT_MAX;
		int Count = 0;
		for (const auto& a : People)
		{
			if (a.second < Ranking)
			{
				Ranking = a.second;
				Count++;
			}
		}
		cout << Count << "\n";
	}
	

	return 0;
}