#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{

	map<int, int> xhash;
	map<int, int> yhash;

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		xhash[x]++;
		yhash[y]++;
	}

	for (auto a : xhash)
	{
		if (a.second == 1)
			cout << a.first << " ";
	}
	for (auto a : yhash)
	{
		if (a.second == 1)
			cout << a.first << " ";
	}


}



