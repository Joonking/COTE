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

//배열 사용 방식
// 
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//// 밭
//int Bat[51][51] = { 0 };
//bool Visited[51][51] = { false };
//
//// 상하좌우
//int Dy[4] = { -1, 1, 0, 0 };
//int Dx[4] = { 0, 0, -1, 1 };
//
//void BFS(int y, int x, int YSize, int XSize)
//{
//    queue<pair<int, int>> Queue;
//    Queue.push({ y, x });
//    Visited[y][x] = true;
//
//    while (Queue.empty() == false)  // while 조건 수정
//    {
//        pair<int, int> Front = Queue.front();
//        Queue.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int NewY = Front.first + Dy[i];
//            int NewX = Front.second + Dx[i];
//
//            if (NewY < 0 || NewX < 0 || NewY >= YSize || NewX >= XSize)
//                continue;
//
//            if (Visited[NewY][NewX] == false && Bat[NewY][NewX] == 1)
//            {
//                Visited[NewY][NewX] = true;
//                Queue.push({ NewY, NewX });
//            }
//        }
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int T;
//    cin >> T;
//
//    for (int i = 0; i < T; i++)
//    {
//        int M, N, K;
//        cin >> M >> N >> K;
//
//        // 배열 초기화
//        fill(&Bat[0][0], &Bat[50][51], 0);
//        fill(&Visited[0][0], &Visited[50][51], false);
//
//        for (int j = 0; j < K; j++)
//        {
//            int X, Y;
//            cin >> X >> Y;
//            Bat[Y][X] = 1;
//        }
//
//        // 지렁이 수
//        int Count = 0;
//
//        for (int y = 0; y < N; y++)
//        {
//            for (int x = 0; x < M; x++)
//            {
//                if (Bat[y][x] == 1 && Visited[y][x] == false)
//                {
//                    BFS(y, x, N, M);
//                    Count++;
//                }
//            }
//        }
//
//        cout << Count << "\n";
//    }
//
//    return 0;
//}
