#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int Max = arr[N - 1];

	for (int i=0;i<arr.size();i++)
	{
		int M = arr[i]*(arr.size()-i);
		if (Max < M)
		{
			Max = M;
		}
	}

	cout << Max;
}




