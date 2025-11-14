#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	set<int> S;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;
		S.insert(Temp);
	}

	for (int i : S)
	{
		cout << i << " ";
	}


	return 0;
}