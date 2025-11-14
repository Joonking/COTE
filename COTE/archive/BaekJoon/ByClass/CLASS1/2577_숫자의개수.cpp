#include <iostream>
#include <string>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	long long Sum = A * B * C;
	string StringSum = to_string(Sum);

	int NumArray[10] = { 0 };

	for (char C : StringSum)
	{
		NumArray[C - '0']++;
	}

	for (int i : NumArray)
	{
		cout << i << endl;
	}
}