#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;		//N : 세로크기, M :가로 크기
char campus[600][600];
bool visited[600][600];
int answer = 0;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void BFS(pair<int, int> start)
{
	queue<pair<int, int>> Queue;
	Queue.push(start);
	visited[start.first][start.second] = true;

	while (Queue.empty() == false)
	{
		int nowY = Queue.front().first;
		int nowX = Queue.front().second;
		Queue.pop();
		for (int i = 0; i < 4; i++)
		{
			int y = nowY + dy[i];
			int x = nowX + dx[i];

			if (y < 0 || y >= N || x < 0 || x >= M)
				continue;

			if (visited[y][x] == false && campus[y][x] != 'X')
			{
				visited[y][x] = true;
				if (campus[y][x] == 'P')
					answer++;
				Queue.push(make_pair(y, x));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	pair<int, int> start;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			char temp;
			cin >> temp;
			campus[i][k] = temp;
			if (temp == 'I')
			{
				start.first = i;
				start.second = k;
			}
		}
	}

	BFS(start);

	if (answer == 0)
		cout << "TT";
	else
		cout << answer;


}


