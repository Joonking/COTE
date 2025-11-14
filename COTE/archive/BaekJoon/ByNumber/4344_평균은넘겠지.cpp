#include <iostream>

using namespace std;
int main()
{
	int C, N, Score, Sum = 0, ScoreArr[1000], A=0;
	float avg;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> Score;
			ScoreArr[j] = Score;
			Sum += Score;
		}
		avg = (float)Sum / N;
		for (int k = 0; k < N; k++)
		{
			if (ScoreArr[k] > avg)
				A++;
		}
		cout << fixed;
		cout.precision(3);
		cout << (float)A / N * 100 << "%" << endl;
		Sum = 0; A = 0;
	}
}