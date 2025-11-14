#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;

//첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500)
// 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다. 
int N, M;

//1 : 출발점, 2 : 도착점, 3 : 가중치
typedef tuple<int, int, int> Edge;

//거리 담을 배열 
vector<long> MDistance;
//엣지 리스트
vector<Edge> EdgeList;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	MDistance.resize(N + 1);

	//일단 모든 값 max로
	fill(MDistance.begin(), MDistance.end(), LONG_MAX); // 최단거리 배열 초기화

	for (int i = 0; i < M; i++)
	{
		int Start, End, Time;
		cin >> Start >> End >> Time;
		EdgeList.push_back({ Start, End, Time });
	}

	//출발점 1번은 0으로
	MDistance[1] = 0;

	//N-1 번 만큼 반복
	for (int i = 1; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			Edge TempEdge = EdgeList[k];
			int StartNode = get<0>(TempEdge);
			int EndNode = get<1>(TempEdge);
			int Time = get<2>(TempEdge);

			//시작 지점의 MDistance 값이 무한대가 아니고
			//시작 지점의 값 + 가중치 < 검사할 도착 지점의 MDistance 값 보다 크면 업데이트
			if (MDistance[StartNode] != LONG_MAX && MDistance[StartNode] + Time < MDistance[EndNode])
			{
				MDistance[EndNode] = MDistance[StartNode] + Time;
			}
		}
	}

	bool IsMinusCycle = false;
	//음수 사이클 확인 
	//다 돌린 상태에서 한번 더 돌려보고 업데이트 될 값이 있으면 음수 사이클이 존재하는 거임.
	for (int i = 0; i < M; i++)
	{
		Edge TempEdge = EdgeList[i];
		int StartNode = get<0>(TempEdge);
		int EndNode = get<1>(TempEdge);
		int Time = get<2>(TempEdge);

		if (MDistance[StartNode] != LONG_MAX && MDistance[StartNode] + Time < MDistance[EndNode])
		{
			IsMinusCycle = true;
		}
	}

	if (IsMinusCycle == false)
	{
		for (int i = 2; i <= N; i++)
		{
			if (MDistance[i] == LONG_MAX)
				cout << -1 << "\n";
			else
				cout << MDistance[i] << "\n";
		}
	}
	else
	{
		cout << -1 << "\n";
	}

	return 0;
}
