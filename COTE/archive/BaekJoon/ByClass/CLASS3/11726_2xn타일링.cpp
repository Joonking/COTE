#include <iostream>
#include <vector>

using namespace std;

//점화식
// dp[i] 는 2xi 크기의 직사각형을 채우는 방법의 수
//dp[n] = dp[n-1] + dp[n-2]
//  2x5 크기의 직사각형을 생각해봤을때
//  ㅁㅁㅁㅁ | ㅁ	2x(5-1) 에 1이 증가한 경우 2x4크기에 마지막 
//  ㅁㅁㅁㅁ | ㅁ   2x1 크기의 직사각형을 넣는 경우만 있음.
//  ㅁㅁㅁ | ㅁㅁ	2x(5-2) 에 2가 증가한 경우 2x3크기에 마지막
//  ㅁㅁㅁ | ㅁㅁ	1x2 크기의 직사각형을 위아래로 놓는 경우 하나 밖에 없음.
// 즉 5의 경우 4, 3 의 경우를 더해주면 가짓수가 나옴.
// dp[5] = dp[4] + dp[3]

int main() {

	int n;
	cin >> n;

	vector<int> dp;
	dp.push_back(1);
	dp.push_back(2);
	for (int i = 2; i < n; i++) {
		dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
	}
	cout << dp[n - 1];

	return 0;
}