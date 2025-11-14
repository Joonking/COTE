#include <iostream>
#include <string>

using namespace std;

char map[100][100];
bool visited[100][100];

int dx[4] = { 0,0,-1,1 };  //상하좌우, x가 가로 y가 세로 좌측상단이 0,0
int dy[4] = { -1,1,0,0 };

void DFS(int x, int y, int n)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int tempX = x + dx[i];
		int tempY = y + dy[i];

		if (tempX < 0 || tempX >n || tempY<0 || tempY>n)
			continue;

		if (visited[tempY][tempX] == false && map[tempY][tempX] == map[y][x])
			DFS(tempX, tempY, n);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string tempStr;
		cin >> tempStr;
		for (int j=0;j<tempStr.size();j++)
		{
			map[i][j] = tempStr[j];
		}
	}

	int sum = 0;

	//정상
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false)
			{
				sum++;
				DFS(j,i,N);
			}
		}
	}
	cout << sum << " ";

	sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'R')
				map[i][j] = 'G';
		}
	}

	//적녹색맹
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false)
			{
				sum++;
				DFS(j, i, N);
			}
		}
	}

	cout << sum << endl;

}