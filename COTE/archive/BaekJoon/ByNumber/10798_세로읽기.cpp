#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> arr;
	int strMax = 0;

	while (true)
	{
		string temp;
		cin >> temp;
		if (strMax < temp.size())
			strMax = temp.size();
		if (temp.size() == 0) break;
		arr.push_back(temp);
	}

	string answer;

	for (int i = 0; i < strMax; i++)
	{
		for (int k = 0; k < arr.size(); k++)
		{
			if (arr[k].size() > i)
			{
				answer += arr[k][i];
			}
		}
	}

	cout << answer;

}