#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <int, int> map;
int N, M, card;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> card;
		map[card]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> card;
		cout << map[card] << " ";
	}
}




