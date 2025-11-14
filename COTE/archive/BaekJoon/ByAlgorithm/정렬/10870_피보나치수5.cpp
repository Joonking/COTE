#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
	int N;
	cin >> N;

	cout << Fibonacci(N);
}