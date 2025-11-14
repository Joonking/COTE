#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> Ai(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Ai[i];
	}
	int B, C;
	cin >> B >> C;
	
	long long Count = 0;

	for (int i : Ai)
	{
		Count++;
		int People = i - B;
		if (People > 0)
		{
			Count += (People + C - 1) / C;
		}
	}

	cout << Count;

	return 0;
}