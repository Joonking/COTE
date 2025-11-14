#include <iostream>
using namespace std;

int checkArr[4];				//비밀번호 체크 배열
int myArr[4];				//현재 상태 배열
int checkSecret = 0;		//몇 개의 문자에 대한 개수를 충족했는지 판단하는 변수
void Add(char c);			//문자 더하기 함수
void Remove(char c);		//문자 빼기 함수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;  //S : 문자열 크기, P : 부분 문자열 크기
	cin >> S >> P;
	int count = 0;		//가능한 비번 개수
	string A;  //문자열 데이터
	cin >> A;

	for (int i = 0; i < 4; i++)
	{
		cin >> checkArr[i];
		if (checkArr[i] == 0)
		{
			checkSecret++;
		}
	}

	for (int i = 0; i < P; i++)  //초기 P부분 문자열 처리
	{
		Add(A[i]);
	}
	if (checkSecret == 4)
	{
		count++;
	}

	for (int i = P; i < S; i++)
	{
		int j = i - P;
		Add(A[i]);
		Remove(A[j]);

		if (checkSecret == 4)
		{
			count++;
		}
	}
	cout << count++ << "\n";

}

//새로 들어온 문자를 처리하는 함수
void Add(char c)
{
	switch (c)
	{
	case 'A':
		myArr[0]++;
		if (myArr[0] == checkArr[0])
			checkSecret++;
		break;
	case 'C':
		myArr[1]++;
		if (myArr[1] == checkArr[1])
			checkSecret++;
		break;
	case 'G':
		myArr[2]++;
		if (myArr[2] == checkArr[2])
			checkSecret++;
		break;
	case 'T':
		myArr[3]++;
		if (myArr[3] == checkArr[3])
			checkSecret++;
		break;
	}
}

void Remove(char c)
{
	switch (c)
	{
	case 'A':
		if (myArr[0] == checkArr[0])
			checkSecret--;
		myArr[0]--;
		break;
	case 'C':
		if (myArr[1] == checkArr[1])
			checkSecret--;
		myArr[1]--;
		break;
	case 'G':
		if (myArr[2] == checkArr[2])
			checkSecret--;
		myArr[2]--;
		break;
	case 'T':
		if (myArr[3] == checkArr[3])
			checkSecret--;
		myArr[3]--;
		break;
	}
}
