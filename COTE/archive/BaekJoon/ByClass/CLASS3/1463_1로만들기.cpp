//바텀업 방식으로 구현하기
//바텀업 : 작은 부분 문제부터 문제를 해결하면서 큰문제로 확장해 나가는 방식
//1부터 N까지의 DP 테이블을 만들고
// 1에서 N으로 DP 테이블을 채우는 방식으로 풀기

//문제 점화식
// D[i] : i에서 1로 만드는 데 걸리는 최소 연산 횟수
// D[i] = D[i-1] + 1										
//		ex > D[2] = D[1] + 1 : 2에서 1로 만드는데 걸리는 횟수는 2에서 -1 하면 되니까 
//									  반대로 1의 횟수에 +1을 해주는거임.
// if(i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1)		
//		ex > D[6] = min( D[6] , D[3] + 1)   : D[6]은 D[5]에서 +1 한값, 그 값과 
//														6을 2로 나눈 D[3]의 횟수의 값에 +1 한 값과 비교
//														더 작은 값을 가지는 애로 변경
// if(i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1)		3으로 나누는 연산이 가능함


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int N;
static vector<int> D;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	D.resize(N + 1);
	D[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0)
		{
			D[i] = min(D[i], D[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			D[i] = min(D[i], D[i / 3] + 1);
		}
	}

	cout << D[N];

}