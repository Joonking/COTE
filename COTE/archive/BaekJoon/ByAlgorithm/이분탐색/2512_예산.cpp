#include "utils/fileio.h"  // 제출 시 삭제

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> budgets(N);
    int maxBudget = 0;
    long long totalRequest = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> budgets[i];
        maxBudget = max(maxBudget, budgets[i]);
        totalRequest += budgets[i];
    }

    long long M;
    cin >> M;

    // 모든 요청을 만족할 수 있는 경우
    if (totalRequest <= M)
    {
        cout << maxBudget << '\n';
    }
    else
    {
        // 이분탐색으로 최적의 상한액 찾기
        int left = 0, right = maxBudget;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;  // mid = 상한액 후보

            // mid를 상한액으로 했을 때 총 배정액 계산
            long long sum = 0;
            for (int i : budgets)
            {
                sum += (i <= mid) ? i : mid;
            }

            // 예산 이내면 더 큰 상한액 시도
            if (sum <= M)
            {
                ans = max(ans, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}