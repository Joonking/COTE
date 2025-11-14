#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, SNum;

// 맵
int Map[101][101];
// 방문 배열
bool Visited[101][101] = { false, };

// 같은 땅들을(Y, X) 묶어서 하나의 섬(vector)으로 만듬.
vector<pair<int, int>> Mlist;
// 그러한 섬들의 리스트
vector<vector<pair<int, int>>> IslandList;

// 상하좌우
int Dy[4] = { -1, 1, 0, 0 };
int Dx[4] = { 0, 0, -1, 1 };

// BFS를 통해 섬을 탐색하고 같은 섬으로 묶음
void BFS(int Y, int X) 
{
    // 일단 y, x 섬 추가
    queue<pair<int, int>> Queue;
    Queue.push({ Y, X });
    Mlist.clear();
    Mlist.push_back({ Y, X });
    Visited[Y][X] = true;
    Map[Y][X] = SNum;

    while (!Queue.empty()) 
    {
        int FrontY = Queue.front().first;
        int FrontX = Queue.front().second;
        Queue.pop();

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) 
        {
            int TempY = FrontY + Dy[i];
            int TempX = FrontX + Dx[i];

            if (TempY < 0 || TempX < 0 || TempY >= N || TempX >= M)
                continue;

            // 현재 방문한 적이 없고 바다가 아니면 같은 섬으로 취급
            if (Visited[TempY][TempX] == false && Map[TempY][TempX] != 0)
            {
                Visited[TempY][TempX] = true;
                Queue.push({ TempY, TempX });
                // 같은 섬에 추가
                Mlist.push_back({ TempY, TempX });
                // 같은 섬 표시
                Map[TempY][TempX] = SNum;
            }
        }
    }
}

// 간선 정보 구조체
struct Edge {
    int Start, End, Cost;
    Edge(int S, int E, int C) : Start(S), End(E), Cost(C) {}

    // Edge > Edge 는 Cost가 큰 걸로 정한다.
    bool operator>(const Edge& Temp) const {
        return Cost > Temp.Cost;
    }
};

// 유니온 파인드에 사용할 부모 배열
vector<int> Parent;

// Find 함수: 부모를 찾는 함수 (경로 압축 포함)
int FindFunction(int Num) {
    if (Parent[Num] == Num)
        return Num;
    return Parent[Num] = FindFunction(Parent[Num]);
}

// Union 함수: 두 노드를 연결
void UnionFunction(int A, int B) {
    A = FindFunction(A);
    B = FindFunction(B);
    if (A != B)
        Parent[B] = A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> Map[i][j]; // 맵 정보 저장
        }
    }

    // 각 섬의 번호
    SNum = 1;

    // 각 자리에서 BFS 탐색을 이용하여 섬들을 분리
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            // 바다(0)가 아니고 탐색하지 않은 곳이면 BFS
            if (Map[i][j] != 0 && !Visited[i][j]) 
            {
                BFS(i, j);
                SNum++; // 섬 번호 증가

                // BFS로 인접한 땅들을 묶어 섬(Mlist)을 만들고 
                // 섬 리스트 IslandList에 추가
                IslandList.push_back(Mlist);
            }
        }
    }

    // 오름차순 정렬할 Edge 우선순위 큐
    priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;

    // IslandList 크기는 총 섬의 개수임.
    // 각 섬 지점에서 만들 수 있는 모든 간선을 저장
    for (int i = 0; i < IslandList.size(); i++) 
    {
        // 현재 섬
        vector<pair<int, int>> NowIsland = IslandList[i];

        // 섬의 모든 지점을 탐색
        for (size_t k = 0; k < NowIsland.size(); k++) 
        {
            // 현재 지점
            int NowY = NowIsland[k].first;
            int NowX = NowIsland[k].second;

            // 현재 지점의 번호
            int NowS = Map[NowY][NowX];

            // 4개의 방향으로 나가볼 거임
            for (int t = 0; t < 4; t++) 
            {
                int DirectionY = Dy[t]; // y 방향
                int DirectionX = Dx[t]; // x 방향
                int BLenght = 0; // 다리 길이

                int TempY = NowY + DirectionY;
                int TempX = NowX + DirectionX;

                // 현재 방향으로 바다를 건너며 다른 섬 탐색
                while (TempY >= 0 && TempX >= 0 && TempY < N && TempX < M) 
                {
                    if (Map[TempY][TempX] == NowS)  // 같은 섬이면 종료
                        break;

                    else if (Map[TempY][TempX] != 0)  // 다른 섬에 도달
                    {  
                        if (BLenght > 1)  // 다리가 1 이상일 때만 간선 추가
                            PQ.push(Edge{ NowS, Map[TempY][TempX], BLenght });
                        break;
                    }
                    else // 바다인 경우
                    {  
                        BLenght++; //다리 길이 증가
                    }
                    TempY += DirectionY;
                    TempX += DirectionX; // 다리 길이 연장
                }
            }
        }
    }

    // 대표 노드 배열은 섬 개수만큼만 필요하니까 
    // SNum 값으로 재조정
    Parent.resize(SNum);

    // 대표 값 일단 자기 자신 값으로 넣기
    for (int i = 1; i < SNum; i++)
    {
        Parent[i] = i;
    }

    int UseEdge = 0;
    int Result = 0;
    // 최소 신장 트리 알고리즘
    while (!PQ.empty())
    {
        Edge Now = PQ.top();
        PQ.pop();

        //대표 노드가 다르면
        if (FindFunction(Now.Start) != FindFunction(Now.End))
        {
            //합치기
            UnionFunction(Now.Start, Now.End);
            Result += Now.Cost;
            UseEdge++;
        }
    }

    // 배열에서 쉬운 index 처리를 위해 sNum을 1부터 시작하였으므로
    // 현재 sNum의 값이 섬의 개수보다 1 많은 상태임
    // 때문에 1 작은 수가 아닌 2 작은 수와 사용 에지를 비교하여 줍니다.
    if (UseEdge == SNum - 2) {
        cout << Result << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}
