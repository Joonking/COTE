#include <iostream>
#include <algorithm>
using namespace std;

int N;
//과일 배열
int Fruit[200000] = { 0 };
//과일 타입 배열
int FruitType[10] = { 0 };
//윈도우 최대 크기 담을 답
int Ans = 0;

//과일 타입 개수 체크
bool CheckFruitCount()
{
	int Count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (FruitType[i])
			Count++;
	}

	//과일 종류가 2개 이하면 true
	if (Count <= 2)
		return true;
	else  //이상이면 false
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Fruit[i];
	}

	int Left = 0, Right = 0;

	while (Left < N)
	{
		while (Right < N)
		{
			//일단 Right에 있는 과일을 타입을 추가
			FruitType[Fruit[Right]]++;
			//Right 한칸 전진
			Right++;

			//현재 과일 타입 2개인지 체크
			if (CheckFruitCount() == false)
			{
				//Right 다시 돌아가고
				Right--;
				//Right에 있던 과일 타입 빼고
				FruitType[Fruit[Right]]--;
				break;
			}
		}
		//Right와 Left의 차이가 곧 윈도우 크기
		Ans = max(Ans, Right - Left);
		//Left에 있던 과일타입 빼주고
		FruitType[Fruit[Left]]--;
		//Left 한칸 전진
		Left++;
	}

	cout << Ans;

	return 0;
}