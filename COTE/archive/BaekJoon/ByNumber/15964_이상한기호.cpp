#include <iostream>
using namespace std;

long AB(long a, long b)
{
	return (a + b) * (a - b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long A, B;
	cin >> A >> B;

	cout << AB(A, B);
}