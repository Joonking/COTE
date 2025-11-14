//내가 푼 코드 ----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int Pan[100][100] = { 0 };
int Depth[100][100] = { 0 };
bool Visited[100][100] = { false };  // 방문 여부 기록

int Dx[4] = { 0, 0, -1, 1 };
int Dy[4] = { -1, 1, 0, 0 };

void BFS()
{
    queue<pair<int, int>> Queue;
    Queue.push({ 0, 0 });
    Depth[0][0] = 1;
    Visited[0][0] = true;  // 시작 지점 방문 처리

    while (!Queue.empty())
    {
        pair<int, int> front = Queue.front();
        Queue.pop();
        int NowDepth = Depth[front.first][front.second];

        // 도착 지점에 도달하면 출력
        if (front.first == N - 1 && front.second == M - 1)
        {
            cout << NowDepth;
            return;
        }

        // 상하좌우 4방향 탐색
        for (int i = 0; i < 4; i++)
        {
            int Y = front.first + Dy[i];
            int X = front.second + Dx[i];

            // 좌표가 범위를 벗어나지 않도록 체크
            if (Y < 0 || Y >= N || X < 0 || X >= M)
                continue;

            // 이동할 수 있는 곳이고 방문하지 않은 경우
            if (Pan[Y][X] == 1 && !Visited[Y][X])
            {
                Queue.push({ Y, X });
                Visited[Y][X] = true;  // 방문 처리
                Depth[Y][X] = NowDepth + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            Pan[i][j] = s[j] - '0';
        }
    }

    BFS();

    return 0;
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