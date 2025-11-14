#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;

	stack<int> ST;
	int sum = 0;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0 && ST.empty() == false)
		{
			sum -= ST.top();
			ST.pop();
		}
		else
		{
			ST.push(temp);
			sum += temp;
		}
	}
	cout << sum << endl;

}





