#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> Materials(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Materials[i];
	}
	//오름차순 정렬
	sort(Materials.begin(), Materials.end());

	//정렬하고 양 끝에서 투포인터로 좁히면서 찾는 방식
	int StartIndex = 0;
	int EndIndex = Materials.size() - 1;
	int Count = 0;

	while (StartIndex < EndIndex)
	{
		int Sum = Materials[StartIndex] + Materials[EndIndex];

		if (Sum == M) //찾는 값이면
		{
			Count++;
			StartIndex++;
			EndIndex--;
		}
		else if (Sum < M)  //작으면 StartIndex 오른쪽으로
		{
			StartIndex++;
		}
		else if (Sum > M)  //크면 EndIndex 안쪽으로 좁히기
		{
			EndIndex--;
		}
	}

	cout << Count;

	return 0;
}