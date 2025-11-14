#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, string, greater<>> NameMap;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string Name, EnterOrLeave;
		cin >> Name >> EnterOrLeave;

		NameMap[Name] = EnterOrLeave;
	}

	for (auto i : NameMap)
	{
		if (i.second == "enter")
			cout << i.first << "\n";
	}

	return 0;
}