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

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> DijkstraList(N + 1);


    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        DijkstraList[u].push_back({ v, w });
    }

    int Start, End;
    cin >> Start >> End;

    vector<int> Ans(N + 1, INT_MAX);
    Ans[Start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({ 0,Start });

    while (PQ.empty() == false)
    {
        int NowDistance = PQ.top().first;
        int NowNode = PQ.top().second;
        PQ.pop();

        if (NowDistance > Ans[NowNode])
            continue;

        for (const auto& a : DijkstraList[NowNode])
        {
            int NextDistance = a.second;
            int NextNode = a.first;

            if (Ans[NextNode] > Ans[NowNode] + NextDistance)
            {
                Ans[NextNode] = Ans[NowNode] + NextDistance;
                PQ.push({ Ans[NextNode], NextNode });
            }
        }
    }

    cout << Ans[End];

    return 0;
}