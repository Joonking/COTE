#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> People(9);

	int Sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> People[i];
		Sum += People[i];
	}

	sort(People.begin(), People.end());
	
	for (int i = 0; i < 8; i++)
	{
		for (int k = i + 1; k < 9; k++)
		{
			if (Sum - People[i] - People[k] == 100)
			{
				for (int t = 0; t < 9; t++)
				{
					if (t == i || t == k)
						continue;
					cout << People[t] << "\n";
				}
				return 0;
			}
		}
	}

	return 0;
}