#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;
	pair<int, int> temp;

	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		temp = make_pair(x, y);
		v.push_back(temp);
		//또는 temp아예 안쓰고 v.push_back({x, y}); 이렇게 해도 됨.
	}

	sort(v.begin(), v.end());

	for (pair<int,int> a : v)
		cout << a.first << ' ' << a.second << '\n';
	
}