#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    // DP 테이블 초기화 (n+1 크기, 매우 큰 수로 초기화)
    vector<int> dp(n + 1, 5001);  // 충분히 큰 값으로 초기화 (5001은 불가능한 경우를 나타냄)
    dp[0] = 0;  // 0kg일 때 봉지 개수는 0개

    // 3kg과 5kg 봉지에 대한 처리
    for (int i = 3; i <= n; i++) {
        if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + 1);  // 3kg 봉지를 사용할 때
        if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);  // 5kg 봉지를 사용할 때
    }

    // 결과 출력
    if (dp[n] == 5001) {
        cout << -1 << endl;  // 정확히 n kg을 만들 수 없는 경우
    }
    else {
        cout << dp[n] << endl;  // 최소 봉지 개수 출력
    }

    return 0;
}
