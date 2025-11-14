//057_1916 최소비용 구하기

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N : 도시 개수, M : 버스 개수
    int N, M;
    cin >> N >> M;

    typedef pair<int, int> node;

    //그래프 인접 리스트
    vector<vector<node>> CityList(N+1);
    //비용 리스트
    vector<int> CostList(N + 1, INT_MAX);
    //방문 리스트
    vector<bool> VisitList(N + 1, false);

    for(int i=0;i<M;i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        CityList[start].push_back({ cost, end});
    }

    int StartCity, EndCity;
    cin >> StartCity >> EndCity;

    //알고리즘 구현 부분.
    //우선순위 큐 선언
	priority_queue<node, vector<node>, greater<node>> PQueue;
    //첫번째 도시의 비용을 0으로 큐에 넣어줌.
	PQueue.push({0, StartCity});
    CostList[StartCity] = 0;

    while(!PQueue.empty())
    {
        node cur_node = PQueue.top();
        PQueue.pop();
        int now = cur_node.second;
        //이미 방문한 도시가 아니라면
        if (!VisitList[now])
        {
            VisitList[now] = true;
            for (node n : CityList[now])
            {
                if (!VisitList[n.second] && CostList[n.second] > CostList[now] + n.first)
                {
                    CostList[n.second] = CostList[now] + n.first;
                    PQueue.push({ CostList[n.second], n.second });
                }
            }
        }
    }

    cout << CostList[EndCity];
}

