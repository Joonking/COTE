#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> Bat;   //배추밭
static vector<vector<bool>> Visited;   //배추밭 방문체크

static int dx[4] = { 0, 0, -1, 1 };		//상, 하, 좌, 우
static int dy[4] = { -1, 1, 0, 0 };    //상, 하, 좌, 우

void DFS(int x, int y)
{
	Visited[y][x] = true;  //우선 방문 처리

	for (int i = 0; i < 4; i++)
	{
		int tempX = x + dx[i];
		int tempY = y + dy[i];

		//상 하 좌 우 못 가는 곳 처리
		if (tempX <0 || tempX >= Bat[0].size() || tempY <0 || tempY >= Bat.size())
			continue;

		//방문하지 않은곳이면서 배추가 심어진 곳이라면 DFS
		if (!Visited[tempY][tempX] && Bat[tempY][tempX] == 1)
			DFS(tempX, tempY);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;  // 테스트 케이스
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int M, N, K;
		//M :배추밭의 가로길이
		//N : 배추밭의 세로길이
		//K : 배추가 심어져 있는 위치의 개수
		cin >> M >> N >> K;

		//이중 벡터 초기화 방법
		//0으로 초기화된 M 크기의 int형 단일 벡터를
		//bat에 N 크기만큼 resize 하겠다.
		Bat.resize(N, vector<int>(M, 0));
		Visited.resize(N, vector<bool>(M, false));

		//배추 있는 곳 표시
		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			Bat[Y][X] = 1;
		}

		int answer = 0;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!Visited[j][i] && Bat[j][i] == 1)
				{
					answer++;
					DFS(i, j);
				}
			}
		}

		cout << answer << endl;
	}

}


