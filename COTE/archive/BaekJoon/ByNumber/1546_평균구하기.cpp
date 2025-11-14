#include <iostream>

using namespace std;

int main()
{
	int N, Score[1000] = { 0 };
	long Max = 0, sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Score[i];
		if (Score[i] > Max)
			Max = Score[i];
		sum += Score[i];
	}

	double result = sum * 100.0 / Max / N;
	cout << result;
}