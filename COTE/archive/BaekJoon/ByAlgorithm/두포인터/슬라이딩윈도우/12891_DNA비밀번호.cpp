#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//S : DNA 길이, P : 부분문자열 길이(윈도우 사이즈)
	int S, P;
	cin >> S >> P;

	string DNA;
	cin >> DNA;

	//체크할 문자 개수 A C G T 순서
	int CheckChar[4] = { 0, };
	for (int i = 0; i < 4; i++)
	{
		cin >> CheckChar[i];
	}

	//Start부터 End 까지가 윈도우
	int StartIndex = 0;
	int EndIndex = P - 1;
	int Count = 0;

	//비교할 배열
	int ACGT[4] = { 0, };
	//0부터 처음 윈도우 크기만큼 일단 ACGT 채우고 시작
	for (int i = StartIndex; i <= EndIndex; i++)
	{
		if (DNA[i] == 'A')
			ACGT[0]++;
		else if (DNA[i] == 'C')
			ACGT[1]++;
		else if (DNA[i] == 'G')
			ACGT[2]++;
		else if (DNA[i] == 'T')
			ACGT[3]++;
	}

	//EndIndex가 DNA 문자열 크기 S 이전까지만
	while (EndIndex < S)
	{
		bool IsPossible = true;
		//비밀번호 가능여부 체크
		for (int i = 0; i < 4; i++)
		{
			//각 문자마다 CheckChar의 개수보다 작으면 최소 조건 충족 x
			if (ACGT[i] < CheckChar[i])
			{
				//불가하다 판단하고 break
				IsPossible = false;
				break;
			}
		}
		//가능한 경우만 ++
		if (IsPossible) Count++;

		//윈도우 오른쪽으로 이동하면서
		//Start는 먼저 빼고 index 증가
		char SubChar = DNA[StartIndex++];   //뺄 문자
		//End는 먼저 index 증가하고 넣기
		char AddChar = DNA[++EndIndex];   //더할 문자

		//문자 빼기
		if (SubChar == 'A')
			ACGT[0]--;
		else if (SubChar == 'C')
			ACGT[1]--;
		else if (SubChar == 'G')
			ACGT[2]--;
		else if (SubChar == 'T')
			ACGT[3]--;

		//문자 넣기
		if (AddChar == 'A')
			ACGT[0]++;
		else if (AddChar == 'C')
			ACGT[1]++;
		else if (AddChar == 'G')
			ACGT[2]++;
		else if (AddChar == 'T')
			ACGT[3]++;
	}

	cout << Count;

	return 0;
}