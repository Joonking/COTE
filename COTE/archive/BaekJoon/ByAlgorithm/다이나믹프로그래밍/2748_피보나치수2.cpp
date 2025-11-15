#include <iostream>

using namespace std;

/*
================================================================================
백준 2748번 - 피보나치 수 2 (브론즈 1)

[문제 요약]
- n번째 피보나치 수를 구하는 문제 (n ≤ 90)
- Fib(0) = 0, Fib(1) = 1, Fib(n) = Fib(n-1) + Fib(n-2)

[풀이 시도 과정]
1. 첫 시도: 순수 재귀 → 시간 초과 (O(2^n), 중복 계산)
2. 두 번째: Bottom-up DP (Tabulation) → 통과 ✅
3. 세 번째: Top-down DP (Memoization) → 통과 ✅

[DP 두 가지 방식 비교]
┌─────────────────┬────────────────────┬─────────────────────┐
│     구분        │ Bottom-up (현재)   │ Top-down (메모이제이션) │
├─────────────────┼────────────────────┼─────────────────────┤
│ 방식            │ 반복문             │ 재귀 + 캐싱          │
│ 계산 순서       │ F(0)→F(1)→...→F(n) │ F(n)→F(n-1)→...     │
│ 모든 값 계산?   │ ⭕ 항상 전체 계산  │ ❌ 필요한 것만      │
│ 스택 오버플로우 │ ❌ 안전            │ ⚠️ n 클 때 위험     │
│ 시간 복잡도     │ O(n)               │ O(n)                │
│ 공간 복잡도     │ O(n)               │ O(n) + 재귀 스택    │
└─────────────────┴────────────────────┴─────────────────────┘

[핵심 개념]
- DP: 중복 계산을 제거하여 지수 시간 → 선형 시간으로 최적화
- 피보나치는 Bottom-up이 더 안전하고 효율적 (재귀 오버헤드 없음)
- long long 필수 (Fib(90) > int 범위)

[배운 점]
- 입출력 최적화는 항상 습관처럼!
- DP 문제는 Bottom-up과 Top-down 둘 다 연습하기
- 순수 재귀는 작은 n에서만 사용 가능
================================================================================
*/

// ========== 최종 통과 코드 (Bottom-up DP) ==========
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    long long Fibo[100]={0};

    Fibo[0]=0;
    Fibo[1]=1;

    // 작은 문제부터 순차적으로 계산
    for (int i=2;i<=n;i++)
    {
        Fibo[i] = Fibo[i-1] + Fibo[i-2];
    }
    cout << Fibo[n];

    return 0;
}


// ========== Top-down DP (Memoization) 방식 ==========
// #include <iostream>
// #include <vector>
// using namespace std;
//
// vector<long long> DP;
//
// long long Fibo(int n)
// {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//
//     // 이미 계산된 값이 있다면 반환 (캐싱)
//     if (DP[n] != -1) return DP[n];
//
//     // 값을 계산 후 저장
//     return DP[n] = Fibo(n - 1) + Fibo(n - 2);
// }
//
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//
//     int n;
//     cin >> n;
//
//     DP.resize(n+1, -1);  // -1로 초기화 (미계산 상태)
//
//     cout << Fibo(n) << endl;
//
//     return 0;
// }


// ========== 잘못된 풀이 (순수 재귀) - 시간 초과 ==========
// int Fibo(int n)
// {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     return Fibo(n-1) + Fibo(n-2);  // 중복 계산 발생! O(2^n)
// }
//
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//
//     int n;
//     cin >> n;
//
//     cout << Fibo(n) << "\n";
//
//     return 0;
// }
