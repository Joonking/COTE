#include<iostream>
using namespace std;

int main()
{
	int N, Target, Current, C[100] = { 0 }, sum=0;
	int min = 300000;
	cin >> N >> Target;

	for (int i = 0; i < N; i++)
		cin >> C[i];

	for (int i = 0; i < N - 2; i++)
	{
		for (int k = i+1; k < N - 1; k++)
		{
			for (int q = k+1; q < N; q++)
			{
				sum = C[i] + C[k] + C[q];
				if (Target - sum < min && Target - sum >= 0)
				{
					min = Target - sum;
					Current = sum;
				}
			}
		}
	}

	cout << Current;

}

