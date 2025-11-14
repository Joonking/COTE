//내가 푼 코드 ----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

static int N, M;  //N : 가로, M : 세로

static int map[100][100] = { 0 };
static bool visited[100][100] = { false };
static int dx[4] = { -1, 1, 0, 0 };    //x가 세로 y가 가로, 상하좌우
static int dy[4] = { 0, 0, -1, 1 };

void BFS(int x, int y)
{
	queue<pair<int, int>> Queue;
	Queue.push(make_pair(x, y));

	while (!Queue.empty())
	{
		pair<int, int> now = Queue.front();
		Queue.pop();
		int nowX = now.first;
		int nowY = now.second;
		visited[nowX][nowY] = true;

		for (int i = 0; i < 4; i++)
		{
			int tempX = nowX + dx[i];
			int tempY = nowY + dy[i];

			if (tempX < 0 || tempX >= N || tempY < 0 || tempY >= M)
				continue;

			if (visited[tempX][tempY] == false && map[tempX][tempY] != 0)
			{
				visited[tempX][tempY] = true;
				map[tempX][tempY] = map[nowX][nowY] + 1;
				Queue.push(make_pair(tempX, tempY));
			}
		}
	}

}

int main()
{
	//cin, cout 시간단축
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string tempStr;
		cin >> tempStr;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = tempStr[j] - '0';
		}
	}

	BFS(0, 0);
	cout << map[N - 1][M - 1] << endl;
}




//책 코드 ---------------------------------------------------------------------------------
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//static int dx[] = { 0, 1, 0, -1 };
//static int dy[] = { 1, 0, -1, 0 };
//static int A[101][101];
//static bool visited[101][101] = { false };
//static int N, M;
//void BFS(int i, int j);
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> N >> M;
//
//    for (int i = 0; i < N; i++) {
//        string s;
//        cin >> s;
//        for (int j = 0; j < M; j++) {
//            A[i][j] = s[j] - '0';
//        }
//    }
//
//    BFS(0, 0);
//    cout << A[N - 1][M - 1] << "\n";
//}
//
//void BFS(int i, int j) {  // BFS구현
//    queue<pair<int, int>> myqueue;
//    myqueue.push(make_pair(i, j));
//    while (!myqueue.empty()) {
//        int now[2];
//        now[0] = myqueue.front().first;
//        now[1] = myqueue.front().second;
//        myqueue.pop();
//        visited[i][j] = true;
//        for (int k = 0; k < 4; k++) {
//            int x = now[0] + dx[k];
//            int y = now[1] + dy[k];
//            if (x >= 0 && y >= 0 && x < N && y < M) { // 좌표 유효성 검사
//                if (A[x][y] != 0 && !visited[x][y]) { // 미방문 정점 검사
//                    visited[x][y] = true;
//                    A[x][y] = A[now[0]][now[1]] + 1; // depth update
//                    myqueue.push(make_pair(x, y));
//                }
//            }
//        }
//    }
//}