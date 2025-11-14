#include <iostream>
#include <vector>
using namespace std;

int n;
int map[128][128];
int white = 0, blue = 0;

void Z(int y, int x, int size)
{
	int temp = map[y][x];
	bool isSame = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp != map[y+i][x+j])
			{
				isSame = false;
				break;
			}
		}
		if (isSame == false) break;
	}

	if (isSame)
	{
		if (temp == 0)
		{
			white++;
		}
		else
		{
			blue++;
		}
	}
	else
	{
		// 1사분면 탐색
		Z(y, x, size / 2);
		// 2사분면 탐색
		Z(y, x + size / 2, size / 2);
		// 3사분면 탐색
		Z(y + size / 2, x, size / 2);
		// 4사분면 탐색
		Z(y + size / 2, x + size / 2, size / 2);
	}



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	Z(0, 0, n);
	cout << white << endl;
	cout << blue << endl;
	
}


