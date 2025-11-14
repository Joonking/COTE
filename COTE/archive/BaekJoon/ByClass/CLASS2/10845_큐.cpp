#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	queue<int> Queue;

	for(int i=0;i<N;i++)
	{
		string tempStr;
		cin >> tempStr;
		if(tempStr == "push")
		{
			int temp;
			cin >> temp;
			Queue.push(temp);
		}
		if (tempStr == "pop")
		{
			if (Queue.empty())
				cout << -1 << endl;
			else
			{
				cout << Queue.front() << endl;
				Queue.pop();
			}
		}
		if (tempStr == "size")
		{
			cout << Queue.size() << endl;
		}
		if (tempStr == "empty")
		{
			if (Queue.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		if (tempStr == "front")
		{
			if (Queue.empty())
				cout << -1 << endl;
			else
			{
				cout << Queue.front() << endl;
			}
		}
		if (tempStr == "back")
		{
			if (Queue.empty())
				cout << -1 << endl;
			else
			{
				cout << Queue.back() << endl;
			}
		}


	}
	

}