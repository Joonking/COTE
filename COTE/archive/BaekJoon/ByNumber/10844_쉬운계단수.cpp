#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    long D[101][11] = { 0 };  // 배열 전체를 0으로 초기화
    long mod = 1000000000;

    // 1자리 숫자의 계단 수 초기화
    for (int i = 1; i <= 9; i++)
    {
        D[1][i] = 1;  // 1자리 수는 1부터 9까지
    }

    // 2자리 이상 숫자의 계단 수 계산
    for (int i = 2; i <= N; i++)
    {
        D[i][0] = D[i - 1][1];  // 끝자리가 0일 때는 그 이전 자리에서 1로 끝나는 경우만 가능
        D[i][9] = D[i - 1][8];  // 끝자리가 9일 때는 그 이전 자리에서 8로 끝나는 경우만 가능

        for (int j = 1; j <= 8; j++)
        {
            D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
        }
    }

    // N자리 숫자의 계단 수 합계 계산
    long Sum = 0;

    for (int i = 0; i <= 9; i++)
        Sum = (Sum + D[N][i]) % mod;

    cout << Sum;

    return 0;
}
