#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int Pan[100][100] = { 0 };
bool Visited[100][100] = { false };

int Dy[] = { -1, 1, 0, 0 };
int Dx[] = { 0, 0, -1, 1 };

int BFS(int Size, int Depth)
{
    int Count = 0;
    for (int i = 0; i < Size; i++)
    {
        for (int k = 0; k < Size; k++)
        {
            // 방문하지 않았고 물높이보다 높은 경우
            if (Visited[i][k] == false && Pan[i][k] > Depth)
            {
                queue<pair<int, int>> Queue;
                Queue.push({ i, k });
                Visited[i][k] = true; // 방문 표시
                Count++; // 새로운 안전 지역 발견

                while (!Queue.empty())
                {
                    pair<int, int> front = Queue.front();
                    Queue.pop();

                    for (int t = 0; t < 4; t++)
                    {
                        int Y = front.first + Dy[t];
                        int X = front.second + Dx[t];

                        // 경계를 벗어나지 않고 방문하지 않은 경우
                        if (Y >= 0 && Y < Size && X >= 0 && X < Size)
                        {
                            // 높이가 Depth보다 높고 방문하지 않은 경우
                            if (Pan[Y][X] > Depth && !Visited[Y][X])
                            {
                                Visited[Y][X] = true; // 방문 표시
                                Queue.push({ Y, X }); // 큐에 추가
                            }
                        }
                    }
                }
            }
        }
    }

    return Count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int MinDepth = 100; // 높이의 최소값 초기화
    int MaxDepth = 0;   // 높이의 최대값 초기화

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cin >> Pan[i][k];
            MinDepth = min(Pan[i][k], MinDepth);
            MaxDepth = max(Pan[i][k], MaxDepth);
        }
    }

    int MaxCount = 0;
    for (int i = 0; i < MaxDepth; i++) // MinDepth부터 시작할 필요 없음
    {
        memset(Visited, false, sizeof(Visited)); // 방문 배열 초기화
        int Count = BFS(N, i); // 현재 물 높이에서의 안전 지역 개수
        MaxCount = max(Count, MaxCount); // 최대 안전 지역 개수 업데이트
    }

    cout << MaxCount;

    return 0;
}
