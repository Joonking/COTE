#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //V : 정점의 개수, E : 간선의 개수, K : 시작 지점
    int V, E, K;
    cin >> V >> E >> K;

    // 인접 리스트 (정점, 가중치)
    vector<vector<pair<int, int>>> DijkstraList(V + 1);

    for (int i = 0; i < E; i++)
    {
        //u : 출발점, v : 도착점, w : 가중치
        int u, v, w;
        cin >> u >> v >> w;
        DijkstraList[u].push_back({ v,w });
    }

    // 최단 거리 저장, 처음에는 모든 정점을 무한대로 초기화
    vector<int> Ans(V + 1, INT_MAX);
    Ans[K] = 0; // 시작점은 거리 0

    // 우선순위 큐 사용 (최소 힙) -> (거리, 정점)
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({ 0, K }); //시작점 K는 거리 0으로 일단 넣기

    while (PQ.empty() == false)
    {
        //현재 노드까지의 거리
        int NowDistance = PQ.top().first;
        //현재 노드
        int NowNode = PQ.top().second;
        PQ.pop();

        // 현재 노드에서 이미 계산된 최단 거리가 더 작다면 무시
        if (NowDistance > Ans[NowNode])
            continue;

        //리스트에서 현재 노드에 붙어있는 노드들을 돌아
        for (const auto& a : DijkstraList[NowNode])
        {
            //다음 노드
            int NextNode = a.first;
            //다음 노드의 가중치
            int NextDistance = a.second;

            // 다음 노드 가는 경로가 이미 정해져 있을때 (없으면 무한대)
            // 그 값보다 현재 노드까지 경로에다가 
            // 현재 노드와 다음노드의 가중치(weight)를 더한 값이
            // 더 작다면 그 값으로 변경
            if (Ans[NextNode] > Ans[NowNode] + NextDistance)
            {
                Ans[NextNode] = Ans[NowNode] + NextDistance;
                PQ.push({ Ans[NextNode], NextNode });
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= V; i++) {
        if (Ans[i] == INT_MAX) {
            cout << "INF\n";
        }
        else {
            cout << Ans[i] << "\n";
        }
    }

    return 0;
}