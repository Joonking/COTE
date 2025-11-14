#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;

	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({y, x});
	}

	sort(v.begin(), v.end());

	for (pair<int, int> a : v)
		cout << a.second << ' ' << a.first << '\n';

}




