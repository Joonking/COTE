#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	unordered_map<string, int> hash;
	vector<string> answer;
	for(int i=0;i<N;i++)
	{
		string temp;
		cin >> temp;
		hash[temp]++;
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		hash[temp]++;
	}
	
	for(auto a : hash)
	{
		if (a.second == 2)
			answer.push_back(a.first);
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for(auto a : answer)
	{
		cout << a << endl;
	}
}









