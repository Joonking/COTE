#include "utils/fileio.h"  // 제출 시 삭제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int K, N;
    cin >> K >> N;
    vector<long long> Lans(K);  // 🔧 수정: int -> long long (랜선 길이 최대 2^31-1)

    // ❌ 실수 1: left = 0으로 시작하면 mid가 0이 되어 0으로 나누기 에러 발생!
    // ✅ 해결: 랜선의 최소 길이는 1cm부터 시작
    long long left = 1;  // 🔧 수정: 0 -> 1
    long long right = 0; // 🔧 수정: int -> long long (오버플로우 방지)
    
    for (int i = 0; i < K; i++)
    {
        cin >> Lans[i];
        right = max(right, Lans[i]);  // 이분탐색 upper bound: 가장 긴 랜선 길이
    }
    long long ans = 0;  // 🔧 수정: int -> long long
    
    while (left <= right)
    {
        long long count = 0;  // 🔧 수정: int -> long long (개수가 int 범위 초과 가능)
        // ❌ 실수 2: mid = (left + right) / 2는 오버플로우 위험
        // ✅ 해결: left + (right - left) / 2 또는 long long 타입 사용
        long long mid = left + (right - left) / 2;
        
        // mid 길이로 잘랐을 때 만들 수 있는 랜선의 개수 계산
        for (long long i : Lans)  // 🔧 수정: int -> long long
        {
            count += i/mid;  // mid는 항상 1 이상이므로 안전
        }
        
        if (count >= N)  // N개 이상 만들 수 있으면
        {
            ans = max(ans, mid);  // 답 갱신 (가능한 최대 길이 찾기)
            left = mid + 1;       // 더 긴 길이로 시도
        }
        else  // N개 미만이면
        {
            right = mid - 1;      // 더 짧은 길이로 시도
        }
    }
  
    cout << ans;
    
    return 0;
}
