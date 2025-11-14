#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//L[N] : 왼쪽에서 부터 N을 포함한 최대 연속 합
	//R[N] : 오른쪽에서부터 N을 포함한 최대 연속 합
	// 인덱스     :   0    1   2   3   4    5      [6]     7      8      9
	//예시배열   :  10  -4   3   1    5   6     [-35]   12    21     -1 
	//L[N]         :  10   6   9  10  15  [21]   -14     12    33    32
	//R[N]         :  21  11 15  12  11   6      -2    [33]    21    -1
	
	// i 번째 수를 삭제했을 때 최댓값 : L[i-1] + R[i+1]
	// L[5] + R[7] = 21 + 33 = 54

	int N;
	cin >> N;
	vector<int> A(N);   //수열 데이터 저장 배열
	vector<int> L(N), R(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	L[0] = A[0];
	int Result = L[0];

	for (int i = 1; i < N; i++)
	{
		//L은 왼쪽에서 부터 N을 포함한 최대 연속 합이니까
		//오른쪽으로 가면서 배열 값을 추가 할지 말지 결정해서 최대값을 업뎃
		L[i] = max(A[i], L[i - 1] + A[i]);
		//우선 하나도 제거하지 않았을 때를 기본 최대값으로 저장
		Result = max(Result, L[i]);
	}

	//R은 오른쪽부터 시작해서 왼쪽으로
	R[N - 1] = A[N - 1];

	for (int i = N - 2; i >= 0; i--)
	{
		R[i] = max(A[i], R[i + 1] + A[i]);
	}

	// L[i-1] + R[i+1] 두 개의 구간 합 배열을 더해주면 
	// i번째 값을 제거한 효과
	for (int i = 1; i < N - 1; i++)
	{
		int Temp = L[i - 1] + R[i + 1];
		Result = max(Result, Temp);
	}
	cout << Result << "\n";

	return 0;
}