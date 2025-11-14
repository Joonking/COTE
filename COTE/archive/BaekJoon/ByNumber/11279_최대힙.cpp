#include <iostream>
#include <queue>

using namespace std;

int N, x;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	priority_queue<int> P_Queue;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (P_Queue.empty())
				cout << 0 << "\n";
			else
			{
				cout << P_Queue.top() << "\n";
				P_Queue.pop();
			}
		}
		else
		{
			P_Queue.push(x);
		}
	}

}








