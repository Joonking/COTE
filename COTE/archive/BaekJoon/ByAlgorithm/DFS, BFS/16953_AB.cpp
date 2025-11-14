#include <iostream>
#include <queue>
using namespace std;

void BFS(int a, int b)
{
	queue<pair<long long, int>> Queue; // long long 사용
	Queue.push({ a, 0 });

	while (!Queue.empty())
	{
		pair<long long, int> Front = Queue.front(); // long long 사용
		Queue.pop();

		if (Front.first == b)
		{
			cout << Front.second + 1;
			return;
		}

		long long X = Front.first * 2;
		long long Y = Front.first * 10 + 1;
		int NowCount = Front.second;

		// 범위를 넘지 않는 경우만 다음 탐색을 수행
		if (X <= b)
		{
			Queue.push({ X, NowCount + 1 });
		}
		if (Y <= b)
		{
			Queue.push({ Y, NowCount + 1 });
		}
	}
	cout << -1; // 목표에 도달할 수 없는 경우
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int A, B;
	cin >> A >> B;

	BFS(A, B);

	return 0;
}
