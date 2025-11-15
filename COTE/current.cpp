#include "utils/fileio.h"  // 제출 시 삭제

#include <iostream>
#include <vector>
using namespace std;

//Bottom-Up 방식

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> DP(N+1);
    
    for (int i=2;i<=N;i++)
    {
        //3번째 연산 : 1을 뺀다
        DP[i] = DP[i-1] + 1;

        if (i%2==0)
        {
            //2번째 연산: 2로 나누어 떨어지면 2로 나눈다.
            // i/2는 자기자신을 2로 나눈애니까 반대로 생각하면
            // 자기자신을 2로 나누면 해당 값이 될 수 있는거
            DP[i] = min(DP[i], DP[i/2]+1);
        }
        if (i%3 == 0)
        {
            DP[i] = min(DP[i], DP[i/3]+1);
        }
    }
    cout << DP[N];
   
    return 0;
}

// Top-Down 방식 (재귀 사용, 메모이제이션 방식)
// int DP[1000001] = {0,};
//
// void MakeOne(int num, int count)
// {
//     if (num == 0)
//         return;
//
//     if (DP[num]!=0 && DP[num] < count)
//     {
//         return;
//     }
//     
//     DP[num] = count;
//     
//     if (num %3 ==0)
//     {
//         MakeOne(num/3, count+1);
//     }
//
//     if (num%2==0)
//     {
//         MakeOne(num/2, count+1);
//     }
//
//     MakeOne(num-1, count+1);
// }
//
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//
//     int N;
//     cin >> N;
//     MakeOne(N, 0);
//     cout << DP[1];
//    
//     return 0;
// }

