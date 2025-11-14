#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> mydeque;
	
	for (int i = 0; i < N; i++)
	{
		int now;  //현재 값
		cin >> now;

		//현재 값이 큐의 마지막 값보다 작아질때까지 pop_back
		while (mydeque.size() && mydeque.back().second > now)
		{
			mydeque.pop_back();
		}

		//현재값을 큐에 push_back
		mydeque.push_back(pair<int, int>(i, now));

		//큐의 맨 앞에 꺼가 범위를 벗어났다면 pop_front
		if (mydeque.front().first <= i - L)
		{
			mydeque.pop_front();
		}

		//큐의 가장 앞에 있는것이 가장 작은 값이므로 출력
		cout << mydeque.front().second << ' ';
	}
}
