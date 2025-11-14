# include <iostream>
#include <string>
using namespace std;

// 용량이 상당히 넉넉한 문제이므로 모든 변수가 long long.
long long L; // 첫 줄에 입력 받을 L
string alphabets; // 둘째 줄에 입력 받을 문자열.
long long M = 1234567891; // 나눠줄 수.
long long R = 31; // 문제에서 r로 주어진 값 31.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long answer = 0;

    cin >> L;
    cin >> alphabets;

    for (long long i = 0; i < L; i++)
    {
        // alphabet에 각각의 알파벳을 저장.
        char alphabet = alphabets[i];
        // 예를 들어 alphabet이 'a'라면 1을 저장해줘야 함.
        // 'a'에서 ('a' - 1)을 빼면 1이 됨.
        alphabet -= ('a' - 1);

        // r은 최초로 31의 0제곱이니까 1을 담아줌.
        long long r = 1;
        // r의 지수만큼 곱함.
        for (int j = 1; j <= i; j++)
        {
            r *= 31;
            // 아래는 r이 너무 커지는 것 방지.
            // 앞서 설명한 원리를 적용한 것.
            if (r > M)
                r = r % M;
        }
        answer += (long long)alphabet * r;
        // 앞서 설명한 원리 적용.
        if (answer > M)
            answer = answer % M;
    }
    cout << answer;
}