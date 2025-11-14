#include <iostream>
using namespace std;

int main()
{
	int Score;
	cin >> Score;
	Score >= 90 ? cout << "A" : Score >= 80 ? cout << "B" : Score >= 70 ? cout << "C" : Score >= 60 ? cout << "D" : cout << "F";
}