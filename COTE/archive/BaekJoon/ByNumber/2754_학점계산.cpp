#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	char first = str[0];
	char second = str[1];
	float score = 0.0f;

	switch (first)
	{
	case 'A':
		score += 4;
		break;
	case 'B':
		score += 3;
		break;
	case 'C':
		score += 2;
		break;
	case 'D':
		score += 1;
		break;
	case 'F':
		score += 0;
		break;
	}

	switch (second)
	{
	case '+':
		score += 0.3;
		break;
	case '-':
		score -= 0.3;
		break;
	}

	//cout 소수점 출력하기
	cout << fixed;
	cout.precision(1);
	cout << score << endl;


}

