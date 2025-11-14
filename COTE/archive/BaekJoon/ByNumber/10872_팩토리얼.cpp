#include <iostream>

using namespace std;

int fact(int n)
{
	if (n)
		return n*fact(n - 1);
	else
		return 1;
}

int main() {
	int N;
	cin >> N;

	cout << fact(N);
}