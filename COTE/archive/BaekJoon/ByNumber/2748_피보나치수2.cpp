#include <iostream>
#include <vector>

using namespace std;

vector<long long> DP;

long long Fibo(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	// 이미 계산된 값이 있다면 반환
	if (DP[n] != -1) return DP[n];

	// 값을 계산 후 저장
	return DP[n] = Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	DP.resize(n+1, -1);

	cout << Fibo(n) << endl;

	return 0;
}