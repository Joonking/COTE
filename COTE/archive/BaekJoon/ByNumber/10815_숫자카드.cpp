#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;

		int left = 0;
		int right = N-1;
		int mid;
		bool isFind = false;
		while (left <= right)
		{
			mid = (left + right) / 2;

			if (arr[mid] == temp)
			{
				cout << 1 << " ";
				isFind = true;
				break;
			}
			if (arr[mid] > temp)
				right = mid - 1;
			else
				left = mid + 1;

		}
		if (isFind == false)
			cout << 0 << " ";
	}


}









