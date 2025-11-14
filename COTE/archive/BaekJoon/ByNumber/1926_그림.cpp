#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;  //n : y, m : x
int board[500][500];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs(int y, int x)
{
	int area = 1;
	board[y][x] = 0;

	queue<pair<int, int>> MyQueue;
	MyQueue.push({ y, x });

	while (MyQueue.empty() == false)
	{
		auto [cy, cx] = MyQueue.front();
		MyQueue.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (board[ny][nx] == 0)
				continue;

			MyQueue.push({ ny,nx });
			board[ny][nx] = 0;
			area++;
		}
	}
	return area;
}

//int dfs(int y, int x)
//{
//	int area = 1;
//	board[y][x] = 0;
//
//	for (int dir = 0; dir < 4; dir++)
//	{
//		int ny = y + dy[dir];
//		int nx = x + dx[dir];
//
//		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
//			continue;
//		if (board[ny][nx] == 0)
//			continue;
//		area += dfs(ny, nx);
//	}
//	return area;
//}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> board[y][x];
		}
	}

	vector<int> areas;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (board[y][x] == 1)
			{
				areas.push_back(bfs(y, x));
			}
		}
	}

	sort(areas.begin(), areas.end());

	if (areas.size() == 0)
	{
		cout << 0 << "\n" << 0 << "\n";
	}
	else
	{
		cout << areas.size() << "\n";
		cout << areas.back() << "\n";  // back() 쓰면 더 깔끔!
	}

	return 0;
}
