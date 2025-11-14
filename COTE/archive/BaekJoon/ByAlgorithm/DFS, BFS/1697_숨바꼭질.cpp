#include <iostream>
#include <queue>

using namespace std;

int N, K;		//N 현재 위치, K 찾을 위치
bool visited[200001];

void BFS(int n)
{
	queue<pair<int, int>> Queue;
	Queue.push(make_pair(n, 0));

	while (Queue.empty() == false)
	{
		int x = Queue.front().first;
		int level = Queue.front().second;
		Queue.pop();

		visited[x] = true;
		if (x == K)
		{
			cout << level << "\n";
			return;
		}
		if (2 * x >= 0 && 2 * x < 100001)
		{
			if (visited[2 * x] == false)
			{
				Queue.push(make_pair(2 * x, level + 1));
			}
		}
		if (x + 1 >= 0 && x + 1 < 100001)
		{
			if (visited[x + 1] == false)
			{
				Queue.push(make_pair(x + 1, level + 1));
			}
		}
		if (x - 1 >= 0 && x - 1 < 100001)
		{
			if (visited[x - 1] == false)
			{
				Queue.push(make_pair(x - 1, level + 1));
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	BFS(N);

}








