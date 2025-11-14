#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> tri;
	tri.push_back(a);
	tri.push_back(b);
	tri.push_back(c);

	sort(tri.begin(), tri.end());
	int answer = 0;
	if (tri[2] >= tri[1] + tri[0])
	{
		answer += tri[0] + tri[1] + (tri[0] + tri[1] - 1);
	}
	else
	{
		answer += tri[0] + tri[1] + tri[2];
	}
	cout << answer;
}






