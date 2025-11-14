#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int Weight = 0;
	int Count = 0;

	for (int i = 0; i < N; i++)
	{
		int TempWeight;
		cin >> TempWeight;

		if (Weight + TempWeight <= M)
		{
			Weight += TempWeight;
			if (Count == 0)
				Count++;
		}
		else
		{
			Weight = TempWeight;
			Count++;
		}
	}

	cout << Count;

	return 0;
}