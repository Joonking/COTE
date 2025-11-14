#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N, Score=0, SumScore=0;
	cin >> N;
	string ch;

	for (int i = 0; i < N; i++)
	{
		cin >> ch;

		for (int j=0; j<ch.length(); j++)
		{
			for (int k = 0; k <= j; k++)
			{
				if (ch[k] == 'O')
					Score++;
				else
					Score = 0;
			}
			SumScore += Score;
			Score = 0;
		}
		cout << SumScore << endl;
		SumScore = 0;
	}
}