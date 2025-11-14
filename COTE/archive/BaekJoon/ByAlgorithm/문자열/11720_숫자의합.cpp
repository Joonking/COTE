#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string Nums;
	cin >> Nums;

	int sum = 0;
	for (char c : Nums)
		sum += (int)c - (int)'0';

	cout << sum;
}