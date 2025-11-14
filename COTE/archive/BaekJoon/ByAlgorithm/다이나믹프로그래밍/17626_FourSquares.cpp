#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int DP[50005] = { 0 };

	//DP[i] : i 값을 만들 때, 제곱수 개수의 최소값
	//DP[i] = DP[i-1] + 1 
	// DP[17] = DP[16] + 1의 제곱 
	//           = 4의제곱 + 1의 제곱 (2개)

    for (int i = 1; i <= N; i++)
    {
        // 초기값 설정: i를 1의 제곱으로만 표현할 때 필요한 개수는 i개
        // DP[i-1]에 1의 제곱을 추가하는 방법으로 초기값을 설정
        DP[i] = DP[i - 1] + 1;

        // 제곱수를 사용할 수 있을 때 더 작은 값을 찾기 위한 반복문
        for (int k = 1; k * k <= i; k++)
        {
            // DP[i]는 현재 값과 DP[i - k*k] + 1 중 더 작은 값을 선택
            // 여기서 k*k는 i보다 작거나 같은 최대 제곱수로, 
            // i에서 k*k를 빼고 남은 수에 대한 최소 제곱수 개수에 1을 더해 업데이트
            DP[i] = min(DP[i], DP[i - k * k] + 1);
        }
    }

	cout << DP[N];

	return 0;
}