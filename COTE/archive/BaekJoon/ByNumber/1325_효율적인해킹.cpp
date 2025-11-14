//047_1325 효율적으로 해킹하기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void BFS(vector<vector<int>> &nodes, vector<int> &answer, int node)
{
	//방문 체크 배열
	vector<bool> visited(nodes.size(), false);

	queue<int> Queue;
	Queue.push(node);		//시작 노드 넣기
	visited[node] = true;		//시작 노드 방문체크

	while (!Queue.empty())
	{
		int now_node = Queue.front();
		Queue.pop();
		for (int i : nodes[now_node])
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				answer[i]++;
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

	int N, M;
	cin >> N >> M;

	vector<vector<int>> Nodes(N+1);
	vector<int> Answer(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int tempA, tempB;
		cin >> tempA >> tempB;
		Nodes[tempA].push_back(tempB);
	}

	for (int i = 1; i < N + 1; i++)
	{
		BFS(Nodes, Answer, i);
	}
	
	int maxVal = 0;
	for (int i = 1; i < N + 1; i++)
	{
		maxVal = max(maxVal, Answer[i]);
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (Answer[i] == maxVal)
			cout << i << " ";
	}

}
