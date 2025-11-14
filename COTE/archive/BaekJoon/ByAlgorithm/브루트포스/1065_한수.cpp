#include <iostream>
using namespace std;

bool IsNum(int n)
{
	if (n < 100)
		return true;
	if (((n / 100) - ((n / 10) % 10)) == ((n / 10)%10 - (n % 10)))
		return true;
	return false;
}

int main()
{
	int N, Count=0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (IsNum(i))
			Count++;
	}
	cout << Count;
}