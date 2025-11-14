#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // n : 도시 개수, m : 도시 간 도로 수, k : k번째 최단 경로
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> DijkstraList(n + 1);

    for (int i = 0; i < m; i++)
    {
        // a : 출발 도시, b : 도착 도시, c : 시간(가중치)
        int a, b, c;
        cin >> a >> b >> c;
        DijkstraList[a].push_back({ b, c });
    }

    // 각 노드의 k번째 최단 경로를 저장하는 우선순위 큐
    vector<priority_queue<int>> Ans(n + 1);

    // 시작점 1에서의 경로를 초기화
    Ans[1].push(0);

    // 우선순위 큐 사용 (최소 힙) -> (거리, 정점)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({ 0, 1 });  // 시작점 1은 거리 0에서 시작

    while (!PQ.empty())
    {
        int NowDistance = PQ.top().first;
        int NowNode = PQ.top().second;
        PQ.pop();

        for (const auto& a : DijkstraList[NowNode])
        {
            int NextDistance = a.second;
            int NextNode = a.first;
            int NewDistance = NowDistance + NextDistance;

            // 다음 노드에 대해 k번째 최단 경로까지만 저장
            if (Ans[NextNode].size() < k)
            {
                // K개 이하일 경우 그냥 추가
                Ans[NextNode].push(NewDistance);
                PQ.push({ NewDistance, NextNode });
            }
            else if (Ans[NextNode].top() > NewDistance)
            {
                // K개 이상이면, 최댓값을 제거하고 새로운 값을 넣음
                Ans[NextNode].pop();
                Ans[NextNode].push(NewDistance);
                PQ.push({ NewDistance, NextNode });
            }
        }
    }

    // k번째 최단 경로 출력
    for (int i = 1; i <= n; i++)
    {
        if (Ans[i].size() == k)
        {
            cout << Ans[i].top() << "\n";
        }
        else
        {
            cout << -1 << "\n";  // k번째 경로가 존재하지 않으면 -1 출력
        }
    }

    return 0;
}
