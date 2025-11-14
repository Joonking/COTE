#include<iostream>
using namespace std;

int BoonHap(int n) {
	int sum = n;
	while (n>0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void Find(int n) {
	for (int i = 1; i <= n; i++)
	{
		if (BoonHap(i) == n)
		{
			cout << i;
			break;
		}
		if (i == n)
			cout << 0;
	}
}

int main()
{
	int N;
	cin >> N;
	Find(N);
}

