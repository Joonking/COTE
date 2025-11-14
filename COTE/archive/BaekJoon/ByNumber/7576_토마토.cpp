#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;  //N : 세로, M : 가로

int pan[1000][1000];

int dy[4] = {-1, 1, 0, 0};	//y가 세로 상하좌우
int dx[4] = {0, 0, -1, 1};	//x가 가로 상하좌우

typedef pair<int, int> ik;
typedef pair<ik, int> node;

void BFS(vector<node> toma)
{
	queue<node> Queue;
	for (auto a : toma)
	{
		Queue.push(a);
	}
	int maxCnt = 0;
	while (Queue.empty() == false)
	{
		node now = Queue.front();
		int nowY = now.first.first;
		int nowX = now.first.second;
		int cnt = now.second;
		Queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int tempY = nowY + dy[i];
			int tempX = nowX + dx[i];

			if (tempY < 0 || tempY >= N || tempX < 0 || tempX >= M)
				continue;
				
			if (pan[tempY][tempX] == 1 || pan[tempY][tempX] == -1)
				continue;

			pan[tempY][tempX] = 1;
			Queue.push(make_pair(make_pair(tempY,tempX), cnt+1));
			if (maxCnt < cnt + 1)
				maxCnt = cnt + 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			if (pan[i][k] == 0)
			{
				cout << -1;
				return;
			}

		}
	}

	cout << maxCnt;

}

int main()
{
	cin >> M >> N;
	vector<node> tomato;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			int temp;
			cin >> temp;
			pan[i][k] = temp;
			if (temp == 1)
			{
				tomato.push_back(make_pair(make_pair(i, k),0));
			}
		}
	}

	BFS(tomato);

}