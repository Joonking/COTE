#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int count = 0;  // 사용한 동전의 개수
    for (int i = n - 1; i >= 0; i--) {  // 큰 가치의 동전부터 탐색
        while (k >= coins[i]) {  // 현재 동전의 가치를 사용할 수 있는 동안 반복
            k -= coins[i];  // 목표 금액에서 현재 동전의 가치를 뺌
            count++;  // 사용한 동전의 개수를 누적
        }
        if (k == 0) break;  // 목표 금액을 만들면 루프 종료
    }
    cout << count << endl;  // 최소 동전 개수 출력

    return 0;
}