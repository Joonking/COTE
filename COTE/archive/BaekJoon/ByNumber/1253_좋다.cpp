#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> Nums(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Nums[i];
	}

	//오름차순 정렬
	sort(Nums.begin(), Nums.end());

	int Count = 0;

	for (int i = 0; i < Nums.size(); i++)
	{
		//찾을 숫자
		int FindNum = Nums[i];

		//투포인터를 양끝에서 좁혀오며 찾는 방식
		int StartIndex = 0;
		int EndIndex = Nums.size() - 1;

		while (StartIndex < EndIndex)
		{
			long Sum = Nums[StartIndex] + Nums[EndIndex];

			if (Sum == FindNum)  //찾았으면
			{
				if (StartIndex != i && EndIndex != i) //자기 자신이 선택되는거 방지
				{
					Count++;
					break;
				}
				if (StartIndex == i)
					StartIndex++;
				if (EndIndex == i)
					EndIndex--;
			}
			else if (Sum < FindNum)  //작으면
			{
				StartIndex++;
			}
			else if (Sum > FindNum)  //크면
			{
				EndIndex--;
			}
		}
	}

	cout << Count;

	return 0;
}