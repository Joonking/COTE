#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

//V : 정점의 수, E : 간선의 개수, P : 건우의 위치
int V, E, P;

//first : 거리, second : 도시
vector<vector<pair<int, int>>> CityList;
//각 도시마다 최단 거리 값을 저장할 배열
vector<int> Dijkstra;
//건우 위치부터 도착까지 거리 값을 저장할 배열
vector<int> DijkstraFromGunWoo;
//오름차순 우선순위 큐 first : 거리, second : 도시
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
//방문 배열
vector<bool> Visited;

void CalcDijkstra(vector<int>& DijkstraList, int StartCity)
{
	//방문 배열 초기화
	fill(Visited.begin(), Visited.end(), false);

	//출발점은 0으로
	DijkstraList[StartCity] = 0;
	PQ.push({ 0, StartCity });

	while (PQ.empty() == false)
	{
		int NowDistance = PQ.top().first;
		int NowCity = PQ.top().second;
		PQ.pop();

		if (Visited[NowCity])
			continue;

		Visited[NowCity] = true;

		for (const auto& a : CityList[NowCity])
		{
			int NextDistance = a.first;
			int NextCity = a.second;

			if (DijkstraList[NextCity] > DijkstraList[NowCity] + NextDistance)
			{
				DijkstraList[NextCity] = DijkstraList[NowCity] + NextDistance;
				PQ.push({ NextDistance, NextCity });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E >> P;

	CityList.resize(V + 1);
	Dijkstra.resize(V + 1, INT_MAX);
	DijkstraFromGunWoo.resize(V + 1, INT_MAX);
	Visited.resize(V + 1, false);
	
	for (int i = 0; i < E; i++)
	{
		int Start, End, Distance;
		cin >> Start >> End >> Distance;
		//도시는 양방향
		CityList[Start].push_back({ Distance, End });
		CityList[End].push_back({ Distance, Start });
	}

	CalcDijkstra(Dijkstra, 1);
	CalcDijkstra(DijkstraFromGunWoo, P);

	//1에서 P점 까지 간다음. P점에서 V까지 가는 경로가 
	// 1에서 V점까지 가는 경로 보다 작으면 구출 가능
	// 1 -> P -> V   <=    1 -> V
	if (Dijkstra[P] + DijkstraFromGunWoo[V] <= Dijkstra[V])
	{
		cout << "SAVE HIM" << "\n";
	}
	else
		cout << "GOOD BYE" << "\n";

	return 0;
}