#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int A, B;
	cin >> A >> B;
	unordered_map<int, int> Umap;
	for (int i = 0; i < A; i++)
	{
		int temp;
		cin >> temp;
		Umap[temp] = 1;
	}
	for (int i = 0; i < B; i++)
	{
		int temp;
		cin >> temp;
		Umap[temp]++;
	}
	int Count = 0;
	for (auto a : Umap)
	{
		if (a.second == 1)
			Count++;
	}
	cout << Count;

	return 0;
}