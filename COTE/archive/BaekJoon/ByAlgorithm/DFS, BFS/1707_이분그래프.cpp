#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& List, vector<int>& ColorList, int Num, bool* Find)
{
	queue<int> Queue;
	Queue.push(Num);
	ColorList[Num] = 1;

	while (Queue.empty() == false)
	{
		int front = Queue.front();
		Queue.pop();

		for (int i : List[front])
		{
			if (ColorList[i] == 0)  //방문하지 않은 노드라면
			{
				//이전 노드랑 색상 다르게 칠하기 1이면 2, 2면 1
				if (ColorList[front] == 1)
					ColorList[i] = 2;
				else if (ColorList[front] == 2)
					ColorList[i] = 1;

				Queue.push(i);
			}
			else // 방문한 곳을 다시 만난 경우
			{
				//이전 노드와 색상이 같은 노드면 이분 그래프 안됨
				if (ColorList[front] == ColorList[i])
				{
					*Find = true;
					return;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int V, E;
		cin >> V >> E;

		//노드 리스트
		vector<vector<int>> NodesList(V + 1);
		//노드별 색상을 담을 리스트 
		// !Point! : 인접 노드끼리 색상만 다르면 이분 그래프, 같으면 이분그래프 안됨 
		//    0 : 방문하지 않은 노드
		//    1 : 색상 1번
		//    2 : 색상 2번
		vector<int> Color(V + 1, 0);

		//노드, 엣지 입력받기
		for (int i = 0; i < E; i++)
		{
			int TempA, TempB;
			cin >> TempA >> TempB;
			NodesList[TempA].push_back(TempB);
			NodesList[TempB].push_back(TempA);
		}
		bool Find = false;  //이분 그래프 아닌것을 찾자

		//모든 노드가 다 이어지지 않은 경우 있을 수 있음.
		//모든 노드에 대해서 BFS
		for (int i = 1; i <= V; i++)
		{
			if (Find)
				break;  //이분 그래프 아니면 종료
			if (Color[i] == 0)
			{
				BFS(NodesList, Color, i, &Find);
			}
		}
		if (Find)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}

	return 0;
}