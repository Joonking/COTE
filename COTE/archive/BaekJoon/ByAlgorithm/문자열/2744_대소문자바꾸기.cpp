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

	for (int i=0;i<str.size();i++)
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		else
			str[i] = tolower(str[i]);
	}

	cout << str;
}

//소문자 판별 islower(str[i])		-> 소문자가 아니라면 0반환
//대문자 판별 isupper(str[i])		-> 대문자가 아니라면 0반환
//소문자 변환 tolower(str[i])
//대문자 변환 toupper(str[i])