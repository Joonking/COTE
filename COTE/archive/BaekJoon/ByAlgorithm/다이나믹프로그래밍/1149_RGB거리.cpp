#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int RGB[1001][3] = { 0 };

	int Rsum = 0;
	int Gsum = 0;
	int Bsum = 0;

	for (int i = 0; i < N; i++)
	{
		int R, G, B;
		cin >> R >> G >> B;
		RGB[i][0] = R;
		RGB[i][1] = G;
		RGB[i][2] = B;
	}

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			Rsum += RGB[i][k];
		}
	}



	return 0;
}