#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, t, a[10001] = { 0 };
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		a[t] += 1;
	}

	for (int i = 1; i < 10001; i++)
	{
		for (int k = 0; k < a[i]; k++)
			cout << i << '\n';
	}

}
