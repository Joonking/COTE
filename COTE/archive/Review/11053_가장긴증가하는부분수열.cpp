// 백준 11053번 - 가장 긴 증가하는 부분 수열 (LIS)
// 난이도: 실버2
// 알고리즘: DP
// 결과: 틀림 (엣지 케이스 처리 실수)

#include "utils/fileio.h"  // 제출 시 삭제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ❌ 첫 번째 시도 (실패): priority_queue 사용
// - 문제점: LIS는 "부분 수열"이므로 원래 배열의 순서를 유지해야 함
// - priority_queue는 정렬되므로 순서 정보가 사라짐
// - pq.top()과 비교는 "전체가 계속 증가"하는 경우만 작동
// - 반례: [3, 1, 2] → 출력 1 (정답: 2)
//
// 힌트: LIS는 DP로 접근해야 한다!
//   - dp[i] = i번째 원소를 마지막으로 하는 가장 긴 증가 부분 수열의 길이
//   - 각 위치에서 "나보다 앞에 있고, 나보다 작은 값"들의 dp 값 확인

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // ✅ DP 접근법
    // dp[i] : i번째 원소를 마지막으로 포함하는 가장 긴 증가 부분 수열의 길이
    // 초기값: 모두 1 (자기 자신 하나만으로도 길이 1)
    vector<int> dp(N, 1);

    // ❌ 두 번째 시도 (실패): maxDP를 0으로 초기화하고 if문 안에서만 갱신
    // int maxDP = 0;  // ← 문제!
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < i; j++) {
    //         if (A[j] < A[i]) {
    //             dp[i] = max(dp[i], dp[j] + 1);
    //             maxDP = max(dp[i], maxDP);  // ← if문 안에서만 갱신!
    //         }
    //     }
    // }
    // cout << maxDP;  // 출력: 0 (반례: N=1 또는 감소 수열)
    //
    // 반례 1: N=1, A=[10]
    //   - j for문이 실행 안됨 → maxDP = 0 출력 (정답: 1)
    // 반례 2: A=[5, 4, 3, 2, 1]
    //   - A[j] < A[i] 조건이 단 한 번도 만족 안됨 → maxDP = 0 (정답: 1)
    //
    // 교훈: 모든 dp[i]를 확인해야 함! 증가 조건 없어도 dp[i]=1은 유효

    // ✅ 올바른 방법: 이중 for문으로 DP 채우기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)  // i보다 앞에 있는 모든 원소 확인
        {
            if (A[j] < A[i])  // 증가 조건을 만족하면
            {
                // j까지의 LIS 길이 + 현재 원소(1) = i까지의 새로운 후보
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // ✅ dp 배열의 최댓값이 전체 LIS 길이
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}

// 시간 복잡도: O(N^2)
// 공간 복잡도: O(N)
//
// 추가 학습 포인트:
// - O(N log N) 최적화: lower_bound를 활용한 이분탐색 기법
// - LIS 경로 복원: 별도 배열로 이전 인덱스 추적