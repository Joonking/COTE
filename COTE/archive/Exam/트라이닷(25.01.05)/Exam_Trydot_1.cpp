/*
문제 1번

n개의 '('와 m 개의 ')'를 이용해 문자열을 만들려고 합니다. 
이때, 완성된 문자열이 반드시 올바른 괄호 문자열일 필요는 
없으며, 반드시 모든 문자를 사용해야 합니다. 
'('의 개수 n과 ')'의 개수 m이 매개변수로 주어질 때,
n개의 '('와 m개의 ')'를 모두 사용해서 만들 수 있는 
문자열의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
• n은 1이상 16이하의 자연수입니다.
• m은 1이상 16이하의 자연수입니다.
• 정답은 231-1 이하의 자연수입니다.

입출력 예
n           m           result
1           1               2
1           2               3

설명
입출력 예 #1
"()", ")("의 2가지 문자열을 만들 수 있습니다.

입출력 예 #2
"())",")()", ")) ("의 3가지 문자열을 만들 수 있습니다.


*** 핵심 ***
DP[Open][Close]는 현재까지 Open개의 여는 괄호와
Close 개의 닫는 괄호를 사용했을 때, 
가능한 문자열의 수를 저장

메모이제이션 기법으로 이미 계산한 결과를 재사용

*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> DP;

int Count(int n, int m, int Open, int Close)
{
    // 여는 괄호 n, 닫는 괄호 m개를 모두 사용했다면
    //가능한 한가지 경우를 반환
    if (Open == n && Close == m) return 1;

    //여는 괄호나 닫는 괄호의 개수가 주어진 값을 초과하면 
    // 불가능한 경우이므로 0을 반환
    if (Open > n || Close > m)return 0;

    //메모이제이션 
    //이미 계산한 적이 있는 경우, 
    // 저장된 결과를 바로 반환
    if (DP[Open][Close] != -1) return DP[Open][Close];

    //여는 괄호를 추가하거나 닫는 괄호를 추가하는 
    // 두 가지 경우를 재귀적으로 계산
    int AddOpen = Count(n, m, Open + 1, Close);
    int AddClose = Count(n, m, Open, Close + 1);

    //두 경우의 결과를 더한 값을 
    // 메모이제이션 테이블에 저장
    DP[Open][Close] = AddOpen + AddClose;

    return DP[Open][Close];
}

int solution(int n, int m) {
    int answer = 0;

    DP.assign(n + 1, vector<int>(m + 1, -1));

    answer = Count(n, m, 0, 0);

    return answer;
}

int main()
{
    int n = 100, m = 100;

    cout << solution(n, m) << endl;

    return 0;
}