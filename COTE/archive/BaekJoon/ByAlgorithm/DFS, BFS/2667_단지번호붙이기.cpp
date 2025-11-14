#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26] = { 0 };
bool visited[26][26] = { false };

int sum = 0;
vector<int> answer;

int dx[4] = {0,0,-1,1};  //상하좌우, x가 가로 y가 세로 좌측상단이 0,0
int dy[4] = {-1,1,0,0};

void DFS(int x, int y, int n)
{
	visited[y][x] = true;
	sum++;

	for (int i = 0; i < 4; i++)
	{
		int tempX = x + dx[i];
		int tempY = y + dy[i];

		if (tempX < 0 || tempX >= n || tempY < 0 || tempY >= n)
			continue;

		if (!visited[tempY][tempX] && map[tempY][tempX] == 1)
		{
			DFS(tempX, tempY, n);
		}
	}
	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; //지도의 크기
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string tempStr;
		cin >> tempStr;
		for (int j=0; j<tempStr.size();j++)
		{
			if (tempStr[j] == '1')
			{
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j]==false && map[i][j]==1)
			{
				DFS(j, i, N);
				answer.push_back(sum);
				sum = 0;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;

	for (int i : answer)
		cout << i << endl;
}