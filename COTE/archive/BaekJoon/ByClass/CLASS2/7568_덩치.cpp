#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, x, y;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int k = 0; k < n; k++)
		{
			if (i == k) continue;
			
			if (v[i].first < v[k].first && v[i].second < v[k].second)
			{
				count++;
			}
		}
		cout << count + 1 << ' ';
	}
}