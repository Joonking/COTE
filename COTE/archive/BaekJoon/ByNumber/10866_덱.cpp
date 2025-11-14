#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	deque<int> Deque;

	for (int i = 0; i < N; i++)
	{
		string tempStr;
		cin >> tempStr;

		if (tempStr == "push_front")
		{
			int temp;
			cin >> temp;
			Deque.push_front(temp);
		}
		if (tempStr == "push_back")
		{
			int temp;
			cin >> temp;
			Deque.push_back(temp);
		}
		if (tempStr == "pop_front")
		{
			if (Deque.empty())
				cout << -1 << endl;
			else
			{
				cout << Deque.front() << endl;
				Deque.pop_front();
			}
		}
		if (tempStr == "pop_back")
		{
			if (Deque.empty())
				cout << -1 << endl;
			else
			{
				cout << Deque.back() << endl;
				Deque.pop_back();
			}
		}
		if (tempStr == "size")
		{
			cout << Deque.size() << endl;
		}
		if (tempStr == "empty")
		{
			if (Deque.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		if (tempStr == "front")
		{
			if (Deque.empty())
				cout << -1 << endl;
			else
			{
				cout << Deque.front() << endl;
			}
		}
		if (tempStr == "back")
		{
			if (Deque.empty())
				cout << -1 << endl;
			else
			{
				cout << Deque.back() << endl;
			}
		}


	}


}