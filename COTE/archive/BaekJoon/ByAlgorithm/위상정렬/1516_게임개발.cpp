#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	//건물 별 선행이 필요한 건물을 담을 배열
	// 1 - 2,3,4 : 2번 3번 4번 건물을 지으려면 1번이 필요함.
	vector<vector<int>> PrecedeList(N + 1);

	//위상정렬에 사용할 차수 배열
	vector<int> Degree(N + 1);

	//각 건물별 필요 시간
	vector<int> BuildTime(N + 1);

	//결과 배열
	vector<int> Result(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> BuildTime[i];

		//Result에는 우선 각 건물들 필요 시간 담기
		Result[i] = BuildTime[i];

		while (true)
		{
			int NeedNum;   //i건물 짓기 전 필요한 건물 번호
			cin >> NeedNum;
			if (NeedNum == -1)break;

			//NeedNum 건물에 i를 추가
			PrecedeList[NeedNum].push_back(i);
			//차수 배열에는 i번 건물 짓기 전 필요한 건물 개수를 하나 증가
			Degree[i]++;
		}
	}

	//위상 정렬에 사용할 큐
	queue<int> Queue;
	for (int i = 1; i <= N; i++)
	{
		//차수가 0인 건물은 큐에 넣음.
		if (Degree[i] == 0)
			Queue.push(i);
	}

	//위상정렬 시작
	while (Queue.empty() == false)
	{
		int Now = Queue.front();
		Queue.pop();

		for (int i : PrecedeList[Now])
		{
			//건물들이 동시에 건설될 수도 있음.
			//그래서 필요 건물 짓는 시간 + 자기 자신 건물 짓는 시간이랑
			// 이전에 필요시간(다른 필수 건물 짓고 자기 짓는시간들중 최고 치)랑
			// 또 최고치의 값으로 저장함. 
			// 이 값이 바로 필요한 건물들 모두 지은 후 자기 자신을 짓는 최소시간임.
			// ex
			//4 번 건물은 1, 3번 건물을 짓고 지을 수 있음.
			// 근데 1번 건물은 5시간 3번 건물은 2시간이면 짓고 4번은 1시간이라하면
			// 1번 짓고 4번 짓기 = 5 + 1 
			// 3번 짓고 4번 짓기 = 3 + 1
			// 1, 3번 동시에 건물 지을 수도 있으니 둘다 필요한데 더 걸리는 1번 건물
			// 지은 후에 4번 짓는게 맞음.
			// 1+4번 먼저 Result 값에 있을 수 있으니 이 값고 나중 3 + 4번 값을 비교해서
			// 큰 값을 넣는거임.
			Result[i] = max(Result[i], Result[Now] + BuildTime[i]);

			//해당 건물 차수 낮추고
			Degree[i]--;

			//0이면 추가
			if (Degree[i] == 0)
				Queue.push(i);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << Result[i] << "\n";

	return 0;
}