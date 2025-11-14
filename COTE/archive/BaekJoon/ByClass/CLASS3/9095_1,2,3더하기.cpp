#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    // 1, 2, 3을 만들 수 있는 경우의 수를 저장할 배열
    int dp[12] = { 0, };

    dp[1] = 1; // 1을 만들 수 있는 경우의 수
    dp[2] = 2; // 2를 만들 수 있는 경우의 수
    dp[3] = 4; // 3을 만들 수 있는 경우의 수

    // 점화식을 이용하여 4부터 T까지의 경우의 수 계산
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}