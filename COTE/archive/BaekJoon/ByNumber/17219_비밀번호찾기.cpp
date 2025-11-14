#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> hash;

	while (N--)
	{
		string tempKey, tempStr;
		cin >> tempKey >> tempStr;
		hash[tempKey] = tempStr;
	}

	while (M--)
	{
		string temp;
		cin >> temp;
		cout << hash[temp] << "\n";
	}



}



