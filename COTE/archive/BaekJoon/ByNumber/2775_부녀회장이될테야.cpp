#include <iostream>
using namespace std;

int main() {
	
	int t, a[15][15] = { 0 }, k, n;
	cin >> t;

	for (int i = 1; i < 15; i++)
		a[0][i] = i;

	for (int i = 0; i < t; ++i) {
		cin >> k >> n;

		for (int y = 1; y <= k; ++y) {
			for (int x = 1; x <= n; ++x) {
				if (a[y][x]) continue;

				for (int j = 1; j <= x; ++j) {
					a[y][x] += a[y - 1][j];
				}
			}
		}
		cout << a[k][n] << endl;
	}
}




