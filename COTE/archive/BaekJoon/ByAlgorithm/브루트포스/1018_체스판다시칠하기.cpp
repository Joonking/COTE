#include <iostream>
#include <vector>
#include <climits>

using namespace std;

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

//밑에서 char CharBoard[50][50];로 선언하고 2차원 문자배열을
// 함수 매개변수로 보낸다고 할때
//1. 만약 값으로 CharList를 보내고 싶다면
//    int CountWB(char CharList[50][50], int y, int x);
//2.  만약 참조로 CharList를 보내고 싶다면
//int CountWB(const char(&CharList)[50][50], int y, int x);
// ** 주의 char (&CharList)[][] 와 같이 배열 크기를 명시 하지 않으면 컴파일 에러가 남.
// C++ 컴파일러가 배열의 크기를 명시적으로 알아야 메모리 레이아웃을 정확하게 처리할 수 있기 때문
// 대안으로 동적 배열 또는 템플릿을 사용
// int CountWB(char** CharList, int y, int x, int rowSize, int colSize)
// int CountWB(vector<vector<char>>& CharList, int y, int x)

int CountWB(const vector<string>& CharList, int y, int x)
{
	int Count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			int TempY = y + i;
			int TempX = x + k;

			if (WB[i][k] != CharList[TempY][TempX])
				Count++;
		}
	}
	return Count;
}

int CountBW(const vector<string>& CharList, int y, int x)
{
	int Count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			int TempY = y + i;
			int TempX = x + k;

			if (BW[i][k] != CharList[TempY][TempX])
				Count++;
		}
	}
	return Count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	//char CharBoard[50][50];
	vector<string> Board(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Board[i];
	}

	int MinCount = INT_MAX;
	for (int i = 0; i <= N - 8; i++)
	{
		for (int k = 0; k <= M - 8; k++)
		{
			MinCount = min(MinCount, CountWB(Board, i, k));
			MinCount = min(MinCount, CountBW(Board, i, k));
		}
	}

	cout << MinCount;

	return 0;
}