#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N;
	cin >> N;

	map<string, int> UMap;

	while (N--)
	{
		string BookName;
		cin >> BookName;
		UMap[BookName]++;
	}

	int MaxCount = 0;
	string BestSeller;

	for (auto a : UMap)
	{
		if (a.second > MaxCount)
		{
			MaxCount = a.second;
			BestSeller = a.first;
		}
		else if (a.second == MaxCount && a.first < BestSeller)
			BestSeller = a.first;
	}

	cout << BestSeller;

	return 0;
}