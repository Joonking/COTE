#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(const vector<vector<int>>& List, vector<bool>& VisitedList, int StartNode, int Distance)
{
	vector<int> Ans;
	queue<pair<int, int>> Queue;   //노드, 깊이
	Queue.push({ StartNode,0 });
	VisitedList[StartNode] = true;
	while (Queue.empty() == false)
	{
		pair<int, int> Front = Queue.front();
		Queue.pop();

		if (Front.second == Distance)
		{
			Ans.push_back(Front.first);
			continue;
		}

		for (int i : List[Front.first])
		{
			if (VisitedList[i] == false)
			{
				VisitedList[i] = true;
				Queue.push({ i, Front.second + 1 });
			}
		}
	}

	if (Ans.empty())
		cout << -1;
	else
	{
		sort(Ans.begin(), Ans.end());
		for (int i : Ans)
			cout << i << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> NodeList(N + 1);
	vector<bool> Visited(N + 1);
	for (int i = 0; i < M; i++)
	{
		int TempA, TempB;
		cin >> TempA >> TempB;
		NodeList[TempA].push_back(TempB);
	}

	BFS(NodeList, Visited, X, K);

	return 0;
}