#include <iostream>
using namespace std;

int main()
{
	int A, B, C, result;
	cin >> A >> B >> C;

	int Max = A;
	if(A>=B &&A>=C)
	{
		if (B > C)result = B;
		else result = C;
	}
	else if (B >= A && B >= C)
	{
		if (A > C)result = A;
		else result = C;
	}
	else
	{
		if (A > B)result = A;
		else result = B;
	}
	cout << result;
}