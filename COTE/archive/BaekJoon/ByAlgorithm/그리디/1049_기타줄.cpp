#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M; //N : 끊어진 기타줄의 개수, M : 기타줄 브랜드
	cin >> N >> M;

	vector<int> PackageCostList(M);
	vector<int> CostList(M);

	for (int i = 0; i < M; i++)
	{
		cin >> PackageCostList[i] >> CostList[i];
	}

	sort(PackageCostList.begin(), PackageCostList.end());
	sort(CostList.begin(), CostList.end());

	//낱개 가격 제일 싼거의 6개 값이 패키지 제일 싼거 하나 값 보다 싸면
	if (CostList[0] * 6 < PackageCostList[0])
	{
		//모두 낱개로 구입
		cout << CostList[0] * N <<"\n";
	}
	else
	{
		//패키지 필요 수
		int PackageCount = N / 6;
		//낱개 필요 수
		int NatCount = N % 6;

		//패키지 하나 가격이 낱개 가격 * 낱개 개수 보다 작으면
		if (PackageCostList[0] < NatCount * CostList[0])
		{
			//패키지를 하나 더 추가 구매
			cout << (PackageCount + 1) * PackageCostList[0] << "\n";
		}
		else //아니면 패키지 따로 낱개 따로 구매
			cout << PackageCount * PackageCostList[0] + NatCount * CostList[0] << "\n";
	}

	return 0;
}