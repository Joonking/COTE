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
