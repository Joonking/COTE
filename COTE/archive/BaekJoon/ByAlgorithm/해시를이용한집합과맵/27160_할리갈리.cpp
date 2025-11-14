#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	unordered_map<string, int> Umap;

	for (int i = 0; i < N; i++)
	{
		string StrTemp;
		int Count;
		cin >> StrTemp >> Count;
		Umap[StrTemp] += Count;
	}

	for (auto a : Umap)
	{
		if (a.second == 5)
		{
			cout << "YES" << "\n";
			return 0;
		}

	}

	cout << "NO" << "\n";


	return 0;
}