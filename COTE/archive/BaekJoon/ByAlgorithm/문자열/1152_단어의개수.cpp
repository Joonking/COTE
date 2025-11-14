#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

	string s, t;
	getline(cin, s);

	stringstream ss(s);

	int c = 0;
	while (ss >> t)
		c++;

	cout << c;
}