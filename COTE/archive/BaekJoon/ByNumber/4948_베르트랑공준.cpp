#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, rt, cnt = 0;

	while (1) {
		cin >> n;
		if (!n)
			break;

		for (int i = n + 1; i <= 2 * n; i++) {
			rt = sqrt(i);
			if (rt == 1 && i != 1) {
				cnt++;
				continue;
			}
			if (i % 2) {
				for (int j = 2; j <= rt; j++) {
					if (!(i % j))
						break;
					if (j == rt) {
						cnt++;
					}
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
}