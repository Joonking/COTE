#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Count = 1;
	int Start_Index = 1;
	int End_Index = 1;
	int sum = 1;

	while (End_Index != N)
	{
		if (sum == N)
		{
			Count++;
			End_Index++;
			sum += End_Index;
		}
		else if (sum > N)
		{
			sum -= Start_Index;
			Start_Index++;
		}
		else
		{
			End_Index++;
			sum += End_Index;
		}
	}
	cout << Count << "\n";

}