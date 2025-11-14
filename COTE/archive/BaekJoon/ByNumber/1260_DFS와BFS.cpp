#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;

vector<vector<int>> Nodes;
vector<bool> visited;


void DFS(int n)
{
	visited[n] = true;
	cout << n << " ";
	for (int i : Nodes[n])
	{
		if (visited[i] == false)
			DFS(i);
	}
}

void BFS(int n)
{
	queue<int> Queue;
	visited[n] = true;
	Queue.push(n);

	while (Queue.empty() == false)
	{
		int now = Queue.front();
		Queue.pop();
		cout << now << " ";
		for (int i : Nodes[now])
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				Queue.push(i);
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	Nodes.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Nodes[a].push_back(b);
		Nodes[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(Nodes[i].begin(), Nodes[i].end());
	}

	DFS(V);
	fill(visited.begin(), visited.end(), false);
	cout << endl;
	BFS(V);

}