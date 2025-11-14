#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
char Pan[51][51];

//연속된 문자 세기
//큐를 이용해서 비어있으면 추가하고
//비어있지 않으면 들어 있는거랑 비교
// 같으면 추가하고 큐의 사이즈를 max 카운팅
// 다르면 큐 클리어 시키고 해당 문자만 추가

//특정 행 연속된 문자 개수 세기
int RowCount(int Row)
{
	int RowMax = 0;
	queue<char> RowQueue;
	for (int i = 0; i < N; i++)
	{
		if (RowQueue.empty())
			RowQueue.push(Pan[Row][i]);
		else
		{
			if (RowQueue.front() == Pan[Row][i])
			{
				RowQueue.push(Pan[Row][i]);
				int Size = RowQueue.size();
				RowMax = max(RowMax, Size);
			}
			else
			{
				while (RowQueue.empty() == false)
				{
					RowQueue.pop();
				}
				RowQueue.push(Pan[Row][i]);
			}
		}
	}
	return RowMax;
}

//특정 열 연속된 문자 개수 세기
int ColCount(int Col)
{
	int ColMax = 0;
	queue<char> ColQueue;
	for (int i = 0; i < N; i++)
	{
		if (ColQueue.empty())
			ColQueue.push(Pan[i][Col]);
		else
		{
			if (ColQueue.front() == Pan[i][Col])
			{
				ColQueue.push(Pan[i][Col]);
				int Size = ColQueue.size();
				ColMax = max(ColMax, Size);
			}
			else
			{
				while (ColQueue.empty() == false)
				{
					ColQueue.pop();
				}
				ColQueue.push(Pan[i][Col]);
			}
		}
	}
	return ColMax;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string TempStr;
		cin >> TempStr;

		for (int k = 0; k < N; k++)
		{
			Pan[i][k] = TempStr[k];
		}
	}

	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1};
	
	int MaxCount = 0;

	//상하좌우 비교해가면서 스왑 한 다음
	//바뀐 두 행이나 열에 대한 count를 세서 max 체크
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			for (int t = 0; t < 4; t++)
			{
				int TempY = i + dy[t];
				int TempX = k + dx[t];

				if (TempY < 0 || TempX < 0 || TempY >= N || TempX >= N)
					continue;

				//스왑
				swap(Pan[i][k], Pan[TempY][TempX]);

				MaxCount = max(MaxCount, RowCount(i));
				MaxCount = max(MaxCount, RowCount(TempY));
				MaxCount = max(MaxCount, ColCount(k));
				MaxCount = max(MaxCount, ColCount(TempX));

				//돌려 놓기
				swap(Pan[i][k], Pan[TempY][TempX]);
			}
		}
	}

	cout << MaxCount << "\n";

	return 0;
}