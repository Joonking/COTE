#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S;
	cin >> S;

	int Alpabet[26];
	fill(Alpabet, Alpabet + 26, -1);

	for (int i = 0; i < S.size(); i++)
	{
		if (Alpabet[S[i] - 'a'] == -1)
			Alpabet[S[i] - 'a'] = i;
	}

	for (int i : Alpabet)
	{
		cout << i << " ";
	}

	return 0;
}