#include <iostream>
#include <vector>

using namespace std;

int N;

vector<vector<int>> NodeList;
vector<bool> Visited;
vector<int> ParentNodeList;

void DFS(int Node)
{
	if (Visited[Node])
		return;

	Visited[Node] = true;

	for (int i : NodeList[Node])
	{
		if (Visited[i] == false)
		{
			ParentNodeList[i] = Node;
			DFS(i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	NodeList.resize(N + 1);
	ParentNodeList.resize(N + 1);
	Visited.resize(N + 1, false);

	for (int i = 0; i < N - 1; i++)
	{
		int TempA, TempB;
		cin >> TempA >> TempB;
		NodeList[TempA].push_back(TempB);
		NodeList[TempB].push_back(TempA);
	}

	DFS(1);

	for (int i = 2; i <= N; i++)
		cout << ParentNodeList[i] << "\n";

	return 0;
}