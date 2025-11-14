#include <iostream>
using namespace std;
#define MAX 301

int N;
int Arr[MAX];
int DP[MAX];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Arr[i];
	}

	DP[1] = Arr[1];
	DP[2] = Arr[1] + Arr[2];
	DP[3] = max(Arr[1] + Arr[3], Arr[2] + Arr[3]);

	for (int j = 4; j <= N; j++) {
		DP[j] = max(DP[j - 2] + Arr[j], DP[j - 3] + Arr[j - 1] + Arr[j]);
	}

	cout << DP[N];
	return 0;


}



