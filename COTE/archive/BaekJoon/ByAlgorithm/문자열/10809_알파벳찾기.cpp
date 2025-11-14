#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Str;
	cin >> Str;

	int A[26], Count = 0;
	fill_n(A, 26, -1);

	for (int i = 0; i < 26; i++)
	{
		for (char c : Str)
		{
			if ((int)c == (97 + i))
			{
				A[i] = Count;
				break;
			}
			Count++;
		}
		Count = 0;
	}

	for (int i = 0; i < 26; i++)
		cout << A[i] << " ";
}