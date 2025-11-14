#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//우선 한 행에서 켜질 수 있는 행을 찾아봄.
// 조건 1. 켜야하는 램프 수가 K보다 크면 안됨.
// ex > 00000 켜야하는 램프 수 5, K가 4 -> x
// 조건 2. 켜야하는 램프 수는 홀수일때 K는 짝수 (짝수, 홀수 반대 경우도)
// ex > 00000 켜야하는 램프 수가 5, K가 6이면 -> x
// ex > 0000 켜야하는 램프 수 4, K는 5 -> x
// 
// 두 조건을 모두 만족하는 행의 문자열을 map에 저장.
// map은 같은 문자열의 개수를 늘림.
// 즉, 0101 같은 거 4개
//     0011 같은 거 5개
//    이런식으로 같은 문자열 개수의 최대 값이 스위치 눌러서
//    바꿀 수 있는 것들이고 곧 켜진 행의 최대값으로 정답임.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M;

	vector<string> LampsRowList(N);
	map<string, int> OnAbleLampsRow;

	for (int i = 0; i < N; i++)
	{
		cin >> LampsRowList[i];
	}
	cin >> K;

	for (string LampsRow : LampsRowList)
	{
		int OffLampCount = 0;
		for (char Lamp : LampsRow)
		{
			if (Lamp == '0')
			{
				OffLampCount++;
			}
		}
		//조건 1. 켜야하는 램프 수가 K보다 크다면 continue
		if (OffLampCount > K)
			continue;
		//조건 2. K가 짝수 일때, 켜야하는 램프가 홀수면 continue
		if (K % 2 == 0 && OffLampCount%2 ==1)
			continue;
		//조건 2. K가 홀수 일때, 켜야하는 램프가 짝수면 continue
		if (K % 2 == 1 && OffLampCount % 2 == 0)
			continue;

		//여기 도달한 애들은 킬 수 있는 행임.
		OnAbleLampsRow[LampsRow]++;
	}

	int MaxCount = 0;
	for (auto a : OnAbleLampsRow)
	{
		MaxCount = max(MaxCount, a.second);
	}

	cout << MaxCount;

	return 0;
}