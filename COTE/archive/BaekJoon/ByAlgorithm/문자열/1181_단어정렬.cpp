#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<int, string>> v;

	string strTemp;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> strTemp;
		v.push_back({ strTemp.size(), strTemp });
	}
	sort(v.begin(), v.end());

	for (int i = 1; i < n; i++)
	{
		if (v[i - 1].second == v[i].second)
			v[i].first = 100;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].first == 100)
			continue;
		cout << v[i].second << '\n';
	}
}




