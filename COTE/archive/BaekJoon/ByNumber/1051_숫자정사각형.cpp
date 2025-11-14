#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> NumsList(N);
    for (int i = 0; i < N; i++)
    {
        cin >> NumsList[i];
    }

    int MaxSize = 0;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < M; k++)
        {
            // 가능한 최대 SquareSize 계산
            int SquareSize = min(N - 1 - i, M - 1 - k);

            while (SquareSize >= 0)
            {
                if (NumsList[i][k] == NumsList[i + SquareSize][k] &&
                    NumsList[i][k] == NumsList[i][k + SquareSize] &&
                    NumsList[i][k] == NumsList[i + SquareSize][k + SquareSize])
                {
                    MaxSize = max(MaxSize, SquareSize + 1);
                    break; // 조건을 만족하면 더 작은 정사각형은 확인할 필요 없음
                }
                SquareSize--; // SquareSize 감소
            }
        }
    }

    cout << MaxSize * MaxSize << "\n";
    return 0;
}
