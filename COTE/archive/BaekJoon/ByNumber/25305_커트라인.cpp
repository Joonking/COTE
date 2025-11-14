#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N, K, x[1000];
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> x[i];
	
	//sort 내림차순
	sort(x, x + N, greater<int>());

	cout << x[K - 1];

}



