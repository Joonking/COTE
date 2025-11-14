#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	int Min = 1000001, Max = -1000001;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp < Min) Min = temp;
		if (temp > Max) Max = temp;

	}
	cout << Min << " " << Max;

	return 0;
}