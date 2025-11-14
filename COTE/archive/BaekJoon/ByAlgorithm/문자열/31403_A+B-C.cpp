#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B, C;
	cin >> A >> B >> C;

	cout << stoi(A) + stoi(B) - stoi(C) << endl;
	cout << stoi(A + B) - stoi(C);
}