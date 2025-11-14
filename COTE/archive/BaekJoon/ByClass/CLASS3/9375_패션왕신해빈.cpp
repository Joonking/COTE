#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	while (T--)
	{
		cin >> n;
		map<string, int> hash;
		while (n--)
		{
			string temp1, temp2;
			cin >> temp1 >> temp2;

			hash[temp2]++;
		}
		int sum = 1;
		for (auto a : hash)
		{
			sum *= (a.second + 1);
		}
		cout << sum - 1 << "\n";
	}
}



