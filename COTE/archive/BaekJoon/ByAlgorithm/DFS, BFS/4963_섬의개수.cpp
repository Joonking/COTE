#include <iostream>
#include <string>
#include <queue>

using namespace std;

static int w;   //지도 너비
static int h;   //지도 높이

#define MAX 50
static int map[MAX][MAX] = { 0, };
static bool visited[MAX][MAX] = { false };
static int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1};    //x가 세로 y가 가로
static int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1};	//상하좌우, 좌상단, 우상단, 좌하단, 우하단
static int answer = 0;  //섬의 개수

void ClearMap()
{
	fill(&map[0][0], &map[MAX - 1][MAX], 0);
	fill(&visited[0][0], &visited[MAX - 1][MAX], false);
}

void DFS(int x, int y)
{
	visited[x][y] = true;
	for(int i=0;i<8;i++)
	{
		int tempX = x + dx[i];
		int tempY = y + dy[i];

		if (tempX < 0 || tempX >= h || tempY < 0 || tempY >= w)
			continue;

		if(visited[tempX][tempY] ==false && map[tempX][tempY] !=0)
		{
			DFS(tempX, tempY);
		}
	}
}

void BFS(int x, int y)
{
	queue<pair<int, int>> Queue;
	Queue.push(make_pair(x, y));
	visited[x][y] = true;

	while(!Queue.empty())
	{
		pair<int, int> now = Queue.front();
		Queue.pop();
		int nowX = now.first;
		int nowY = now.second;

		for(int i=0;i<8;i++)
		{
			int tempX = nowX + dx[i];
			int tempY = nowY + dy[i];

			if (tempX < 0 || tempX >= h || tempY < 0 || tempY >= w)
				continue;

			if (visited[tempX][tempY] == false && map[tempX][tempY] != 0)
			{
				visited[tempX][tempY] = true;
				Queue.push(make_pair(tempX, tempY));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		ClearMap();
		answer = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		int temp;
		for(int i = 0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin >> temp;
				map[i][j] = temp;
			}
		}

		//DFS로 풀기 --------------------------------------------
		/*for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == false && map[i][j] != 0)
				{
					DFS(i, j);
					answer++;
				}
			}
		}*/
		//----------------------------------------------------------

		//BFS로 풀기 ---------------------------------------------
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == false && map[i][j] != 0)
				{
					BFS(i, j);
					answer++;
				}
			}
		}
		//--------------------------------------------------------

		cout << answer << endl;
	}
	

}