#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N, count=0;
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	int B; 
	cin >> B;
	for (int i : v)
	{
		if (B == i)
			count++;
	}
	cout << count;
}