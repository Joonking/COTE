#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	cin.ignore();
	/*
	cin.ignore()의 동작
		cin.ignore()는 버퍼에서 문자 하나를 "무시"하고 지나가라는 뜻이야.
		가장 많이 쓰는 패턴 :
		cin으로 숫자를 입력받으면, ** 엔터(개행문자 '\n')** 가 버퍼에 남아있어.
		그 상태에서 getline 등 한 줄 입력을 바로 하면, 빈 줄이 들어올 수 있어!
		그래서 불필요한 개행문자 제거 용도로 쓰는 거야.
	*/

	while (T--)
	{
		string line;
		getline(cin, line);
		stringstream ss(line); //stringstream은 문자열을 "cin처럼" 분해해서 꺼낼 수 있게 해주는 도구야!

		int A, B;
		char Comma;
		ss >> A >> Comma >> B;
		cout << A + B << "\n";

	}
}

// line = "1,2"  (문자열로 저장)
//			|
//			V
// + ------------------ +
// | 1 | , | 2 | \0 |          입력 버퍼 (키보드의 입력 데이터는 먼저 입력 버퍼라는 임시 저장소에 들어감. 그리고 이걸 cin, getline, scanf등 함수들이 이 버퍼에서 데이터를 꺼내서 사용함.)
// + ------------------ +
//  ↑  ↑   ↑
//  a  comma  b
//
// stringstream ss(line);
// ss >> a;    // 1을 a에 저장, 커서 한 칸 이동
// ss >> comma; // ','를 comma에 저장, 커서 한 칸 이동
// ss >> b;    // 2를 b에 저장