#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string str;
		getline(cin, str);
		if (str.size() == 0)break;
		cout << str << "\n";
	}

}

/*
공백 포함 문자열 입력받기
1. getline 이용
int main() {
	string s;
	getline(cin, s);
	cout << s;
}
getline을 쓰면 알아서 공백 포함하여 문자열을 입력받는다.

2. cin.getline 이용
int main() {
	char s[100];
	cin.getline(s, 100, '\n');
	cout << s;
}
cin.getline(char배열 이름, 배열크기, 구분문자);
다른점은 엔터말고 특정문자로 입력을 종료시킬 수 있다는 점

3. gets_s 이용
int main() {
	char s[100];
	gets_s(s, sizeof(s));
	cout << s;
}
2번이랑 비슷하다.
gets_s(char배열 이름, 배열크기)
*/