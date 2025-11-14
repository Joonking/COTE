//BFS 버전
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int N;
//vector<vector<int>> nums;
//vector<vector<int>> answer;
//
//void BFS(int start)
//{
//    vector<bool> visited(N, false);  // 방문한 노드 체크용 배열
//    queue<int> Queue;
//    Queue.push(start);
//    while (!Queue.empty())
//    {
//        int now = Queue.front();
//        Queue.pop();
//        for (int i : nums[now])
//        {
//            if (!visited[i])
//            {
//                answer[start][i] = 1;
//                visited[i] = true;
//                Queue.push(i);
//            }
//        }
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> N;
//    nums.resize(N);
//    answer.resize(N, vector<int>(N, 0));  // 0으로 초기화된 NxN 크기의 2차원 벡터 선언
//
//    for (int i = 0; i < N; i++)
//    {
//        for (int k = 0; k < N; k++)
//        {
//            int temp;
//            cin >> temp;
//            if (temp == 1)
//            {
//                nums[i].push_back(k);
//            }
//        }
//    }
//
//    for (int i = 0; i < N; i++)
//    {
//        BFS(i);
//    }
//
//    for (int i = 0; i < N; i++)
//    {
//        for (int k = 0; k < N; k++)
//        {
//            cout << answer[i][k] << " ";
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}

//플로이드-워셜 버전
#include <iostream>

using namespace std;

int N;

int Nodes[101][101] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cin >> Nodes[i][k];
		}
	}

	for (int t = 0; t < N; t++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < N; k++)
			{
				//i->k 경로 중에 i -> t -> k 즉 i -> t 가는 경로가 있고 t -> k 로 가는 경로가 있으면
				// i -> k 로 가는 경로가 있다고 판단하고 1로 연결해줌.
				if (Nodes[i][t] == 1 && Nodes[t][k] == 1)
					Nodes[i][k] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cout << Nodes[i][k] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}