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
	
	//D[i][0] : i 길이에서 끝이 0으로 끝나는 이친수의 개수
	//D[i][1] : i 길이에서 끝이 1로 끝나는 이친수의 개수
	long D[91][2];

	D[1][1] = 1;
	D[1][0] = 0;

	// i-1 번째        i 번째
	// xxx ... 0        xxx ... 00 -> 0은 이전 단꼐의 0과 1로 끝나는 모든 경우에 붙일 수 있음. 
	// xxx ... 1        xxx ... 01  => 1은 이전 단계의 0인 경우에만 붙일 수 있음. D[i-1][0]
	//                   xxx ... 10  -> D[i-1][1] 에 뒤에 0을 붙이는 경우

	// D[i][0] = D[i-1][1] + D[i-1][0]
	// D]i][1] = D[i-1][0]

	for (int i = 2; i <= N; i++)
	{
		D[i][0] = D[i - 1][1] + D[i - 1][0];
		D[i][1] = D[i - 1][0];
	}

	cout << D[N][0] + D[N][1];

	return 0;
}