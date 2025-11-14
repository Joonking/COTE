#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;   //n : 세로, m : 세로
int Map[1000][1000];
int Dist[1000][1000];
bool visited[1000][1000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1};

void BFS(pair<int, int> node)
{
	queue<pair<int, int>> Queue;
	Queue.push(node);
	Dist[node.first][node.second] = 0;
	visited[node.first][node.second] = true;

	while (Queue.empty() == false)
	{
		int nowY = Queue.front().first;
		int nowX = Queue.front().second;
		Queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int y = dy[i] + nowY;
			int x = dx[i] + nowX;

			if (y < 0 || y >= n || x < 0 || x >= m)
			{
				continue;
			}

			if (visited[y][x] == false && Map[y][x] != 0)
			{
				visited[y][x] = true;
				Dist[y][x] = Dist[nowY][nowX] + 1;
				Queue.push(make_pair(y, x));
			}
		}


	}
}

int main()
{
	cin >> n >> m;
	pair<int, int> start;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			int temp;
			cin >> temp;
			if (temp == 2)
			{
				start.first = i;
				start.second = k;
			}
			Map[i][k] = temp;
		}
	}

	BFS(start);

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (Dist[i][k] == 0 && Map[i][k] == 1)
				cout << -1 << " ";
			else
				cout << Dist[i][k] << " ";
		}
		cout << "\n";
	}
}




