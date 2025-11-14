//BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
int board[100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS(int y, int x)
{
	board[y][x] = 1;
	int area = 1;

	queue<pair<int, int>> Queue;
	Queue.push({ y,x });

	while (Queue.empty() == false)
	{
		auto [cy, cx] = Queue.front();
		Queue.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || ny >= M || nx < 0 || nx >= N)
				continue;

			if (board[ny][nx] == 0)
			{
				board[ny][nx] = 1;
				Queue.push({ ny,nx });
				area++;
			}
		}
	}

	return area;
}


int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				board[y][x] = 1;
			}
		}
	}

	vector<int> areas;
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] == 0)
			{
				areas.push_back(BFS(y, x));
			}
		}
	}

	sort(areas.begin(), areas.end());

	cout << areas.size() << "\n";
	for (int i : areas)
		cout << i << " ";

	return 0;
}


//DFS
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int M, N, K;
//int board[100][100];
//int dy[4] = { -1, 1, 0, 0 };
//int dx[4] = { 0, 0, -1, 1 };
//
//int dfs(int y, int x)
//{
//	board[y][x] = 1;
//	int area = 1;
//
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int ny = y + dy[dir];
//		int nx = x + dx[dir];
//
//		if (ny < 0 || ny >= M || nx < 0 || nx >= N)
//			continue;
//
//		if (board[ny][nx] == 0)
//		{
//			area += dfs(ny, nx);
//		}
//	}
//	return area;
//}
//
//
//int main()
//{
//	cin >> M >> N >> K;
//
//	for (int i = 0; i < K; i++)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//
//		for (int y = y1; y < y2; y++)
//		{
//			for (int x = x1; x < x2; x++)
//			{
//				board[y][x] = 1;
//			}
//		}
//	}
//
//	vector<int> areas;
//	for (int y = 0; y < M; y++)
//	{
//		for (int x = 0; x < N; x++)
//		{
//			if (board[y][x] == 0)
//			{
//				areas.push_back(dfs(y, x));
//			}
//		}
//	}
//
//	sort(areas.begin(), areas.end());
//
//	cout << areas.size() << "\n";
//	for (int i : areas)
//		cout << i << " ";
//
//	return 0;
//}