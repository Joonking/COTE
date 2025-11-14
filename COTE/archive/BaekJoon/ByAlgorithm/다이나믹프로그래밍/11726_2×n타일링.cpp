#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	// D[i] : 
	long D[1001];
	long mod = 10007;
	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= N; i++)
		D[i] = (D[i - 1] + D[1 - 2]) % mod;
	return 0;
}