#include <iostream>
using namespace std;
int main()
{
	int N1, N2, count=0;
	cin >> N1;
	N2 = N1;
	while (true)
	{
		count++;
		if (N1 < 10)
			N1 * 10;

		int A = N1 / 10;
		int B = N1 % 10;

		N1 = B * 10 + ((A + B) % 10);
		if (N1 == N2)
			break;
	}
	cout << count;
}