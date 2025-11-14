#include <iostream>
#include <vector>

using namespace std;

vector<int> Nums;
vector<int> TempNums;

void MergeSort(int StartIndex, int EndIndex)
{
	//Strat와 End가 같으면 return 
	if (EndIndex - StartIndex < 1)
		return;

	//중간 인덱스
	int MiddleIndex = StartIndex + (EndIndex - StartIndex) / 2;

	//Strat와 End가 같을때까지 즉 그룹에 하나의 원소만 있을때까지 재귀
	//왼쪽 그룹
	MergeSort(StartIndex, MiddleIndex);
	//오른쪽 그룹
	MergeSort(MiddleIndex + 1, EndIndex);

	//Nums의 시작부터 끝인덱스 까지 일단 Temp에 담음
	for (int i = StartIndex; i <= EndIndex; i++)
	{
		TempNums[i] = Nums[i];
	}

	//Nums의 합쳐 지는곳의 인덱스
	int MergeIndex = StartIndex;
	//왼쪽 그룹 Index
	int LeftGroupIndex = StartIndex;
	//오른쪽 그룹 Index
	int RightGroupIndex = MiddleIndex + 1;

	//TempNums를 둘로 나눠서 Nums에 다가 합치는거임.
	//LeftGroupIndex은 시작부터 Middle 까지
	//RightGroupIndex는 Middle+1 부터 End 까지
	while (LeftGroupIndex <= MiddleIndex && RightGroupIndex <= EndIndex)
	{
		//왼쪽 그룹에 있는 애가 오른쪽 그룹애 보다 크면
		if (TempNums[LeftGroupIndex] > TempNums[RightGroupIndex])
		{
			//오른쪽 그룹 있는애를 k에 넣고
			Nums[MergeIndex] = TempNums[RightGroupIndex];
			MergeIndex++;  //MergeIndex 증가
			RightGroupIndex++;   //오른쪽 인덱스 증가
		}
		else  //왼쪽 그룹에 있는 애가 오른쪽 그룹애 보다 작으면 
		{
			//왼쪽 애를 k에 넣고
			Nums[MergeIndex] = TempNums[LeftGroupIndex];
			MergeIndex++;
			LeftGroupIndex++;  //왼쪽 인덱스 증가
		}
	}

	// 한쪽 그룹이 모두 선택된 후 남아있는 값 정리하기
	//왼쪽 그룹이 Middle까지 안왔으면
	while (LeftGroupIndex <= MiddleIndex) {
		Nums[MergeIndex] = TempNums[LeftGroupIndex];
		MergeIndex++;
		LeftGroupIndex++;
	}
	//오른쪽 그룹이 End까지 안왔으면
	while (RightGroupIndex <= EndIndex) {
		Nums[MergeIndex] = TempNums[RightGroupIndex];
		MergeIndex++;
		RightGroupIndex++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	Nums.resize(N + 1);
	TempNums.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> Nums[i];
	}

	MergeSort(1, N);

	for (int i = 1; i <= N; i++)
		cout << Nums[i] << "\n";

	return 0;
}