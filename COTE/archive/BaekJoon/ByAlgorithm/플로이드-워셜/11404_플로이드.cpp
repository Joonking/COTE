#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;
long MDistance[101][101] = { 0, };

//첫째 줄에 도시의 개수 n이 주어지고 둘째 줄에는 버스의 개수 m이 주어진다.
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	//i, k가 같은 곳은 자기자신에서 자신으로 가는길이니까 0으로
	//나머지는 큰 값 저장
	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= N; k++)
		{
			if (i == k)
				MDistance[i][k] = 0;
			else
				MDistance[i][k] = 10000001;  //충분히 큰 수로 저장.
			//여기서 LONG_MAX를 쓰면 밑에서 
			//MDistance[i][k] = min(MDistance[i][k], MDistance[i][t] + MDistance[t][k]);
			// 에서 MDistance[i][t] + MDistance[t][k]의 값이 LONG_MAX에 가깝거나 
			// 그 값을 더하게 되면 LONG_MAX를 초과하여 오버플로우가 발생할 수 있음
			//그래서 이 문제에서 비용은 100,000보다 작거나 같은 자연수이다. 라고 했으니
			// 10000001 과 같은 충분히 큰 수로 한거임.
		}
	}

	for (int i = 0; i < M; i++)
	{
		int Start, End;
		long Cost;
		cin >> Start >> End >> Cost;
		
		//시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있으니
		//가장 최소값으로 저장.
		MDistance[Start][End] = min(MDistance[Start][End], Cost);
	}

	//t는 중간 지점임. i에서 k로 가는데 i -> t -> k 로 나눠서 생각
	for (int t = 1; t <= N; t++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int k = 1; k <= N; k++)
			{
				// i -> k 랑   i -> t -> k 중에 최소값으로 i -> k를 업뎃
				MDistance[i][k] = min(MDistance[i][k], MDistance[i][t] + MDistance[t][k]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= N; k++)
		{
			if (MDistance[i][k] == 10000001)
				cout << "0 ";
			else 
				cout << MDistance[i][k] << " ";
		}
		cout << "\n";
	}

	return 0;
}