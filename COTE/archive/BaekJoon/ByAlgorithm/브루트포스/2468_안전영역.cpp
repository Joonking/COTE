#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int Pan[100][100] = { 0 };
bool Visited[100][100] = { false };

int Dy[] = {-1, 1, 0, 0};
int Dx[] = {0, 0, -1, 1};

int BFS(int Size, int Depth)
{
	int Count = 0;
	for (int i = 0; i < Size; i++)
	{
		for (int k = 0; k < Size; k++)
		{
			if (Visited[i][k] == false && Pan[i][k] > Depth)
			{
				queue<pair<int, int>> Queue;
				Queue.push({ i, k });
				Visited[i][k] = true;
				Count++;

				while (Queue.empty() == false)
				{
					pair<int,int> front = Queue.front();
					Queue.pop();

					for (int t = 0; t < 4; t++)
					{
						int Y = front.first + Dy[t];
						int X = front.second + Dx[t];

						// 경계를 벗어나지 않는지 확인
						if (Y >= 0 && Y < Size && X >= 0 && X < Size && Visited[Y][X] == false)
						{
							Visited[Y][X] = true;
							if (Pan[Y][X] > Depth)
							{
								Queue.push({ Y, X });
							}
						}
					}
					
				}

			}
		}
	}

	return Count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int MinDepth = 100;
	int MaxDepth = 1;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cin >> Pan[i][k];
			MinDepth = min(Pan[i][k], MinDepth);
			MaxDepth = max(Pan[i][k], MaxDepth);
		}
	}

	int MaxCount = 0;
	for (int i = MinDepth; i <= MaxDepth; i++)
	{
		memset(Visited, false, sizeof(Visited));
		int Count = BFS(N, i);
		MaxCount = max(Count, MaxCount);
	}

	cout << MaxCount;

	return 0;
}