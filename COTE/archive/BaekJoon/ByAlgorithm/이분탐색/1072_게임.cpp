#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long x, y;
	cin >> x >> y;

	int z = (y * 100) / x;
	if (z >= 99) {
		cout << -1 << "\n";
		return 0;
	}

	int left = 0;
	int right = 1000000000;
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int temp = (100 * (y + mid)) / (x + mid);
		if (z >= temp) {
			ans = mid + 1;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	cout << ans << "\n";

	return 0;
}