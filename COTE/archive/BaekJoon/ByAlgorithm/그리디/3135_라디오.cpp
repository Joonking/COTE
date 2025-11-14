#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int A, B, N;
	cin >> A >> B >> N;

	vector<int> Favorite(N);
	int StartNum = A, Count = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> Favorite[i];
	}

	for (int i : Favorite)
	{
		if (i != 0)
		{
			if (abs(B - StartNum) > abs(B - i))
				StartNum = i;
		}
	}
	
	if (StartNum != A)
		Count = 1;

	while (true)
	{
		if (StartNum > B)
			StartNum--;
		else if(StartNum < B)
			StartNum++;
		else
		{
			cout << Count;
			break;
		}
		Count++;
	}

	return 0;
}