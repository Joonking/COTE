#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<string> Boo(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Boo[i];
	}

	for (const auto& a : Boo)
	{
		for (int i = a.size() - 1; i >= 0; i--)
		{
			cout << a[i];
		}
		cout << "\n";
	}

	return 0;
}