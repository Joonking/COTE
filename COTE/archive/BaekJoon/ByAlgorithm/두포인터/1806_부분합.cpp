#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)	// 배열 입력
		cin >> arr[i];

	int start = 0, end = 0, sum = 0, minLen = INT_MAX;
	while (start <= end) {
		if (sum >= s) {	// 현재 포인터의 합이 s보다 크거나 같으면 start ++
			minLen = min(minLen, end - start);	// 가장 짧은 길이만 저장
			sum -= arr[start++];
		}
		else if (end == n) break;
		else sum += arr[end++];	// end++ 함으로써 sum 증가
	}

	if (minLen == INT_MAX) cout << 0 << endl;	// 불가능 하면 0 출력
	else cout << minLen << endl;
}