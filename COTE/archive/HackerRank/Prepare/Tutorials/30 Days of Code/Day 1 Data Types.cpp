#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>  // for setting precision
#include <string>

using namespace std;

int main() {
    // 초기 데이터
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // 입력 받을 변수들 선언
    int i_input;
    double d_input;
    string s_input;

    // 입력 받기
    cin >> i_input;
    cin >> d_input;
    cin.ignore(); // 버퍼 비우기 (문자열 입력 전 필요)
    getline(cin, s_input);

    // 결과 출력
    cout << i + i_input << endl;

    // 소수점 두 자리까지 출력
    cout << fixed << setprecision(1) << d + d_input << endl;

    // 문자열 합치기
    cout << s + s_input << endl;

    return 0;
}
