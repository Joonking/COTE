#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;

	while (true)
	{
		int MAX = 0, AB = 0;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		MAX = max(a, b);
		MAX = max(MAX, c);

		if (MAX != a) AB += a * a;
		if (MAX != b) AB += b * b;
		if (MAX != c) AB += c * c;

		if (MAX * MAX == AB) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}



