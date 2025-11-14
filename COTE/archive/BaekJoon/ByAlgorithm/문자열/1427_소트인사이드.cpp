#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	sort(str.begin(), str.end(), greater<char>());

	for (char c : str)
		cout << c;


}





//선택정렬

/*

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<int> A(str.size(), 0);

    for (int i = 0; i < str.size(); i++)
    {
        //stoi : 문자열을 int로 변환
        //substr : 문자열 자르기
        //  매개변수 i : 시작위치, 1 : 자를 개수
        A[i] = stoi(str.substr(i, 1));
        //문자 하나를 잘라서 숫자로 바꾸고 
        //vector A에 추가
    }
    for (int i = 0; i < str.length(); i++)
    {
        int Max = i;
        for (int j = i + 1; j < str.length(); j++)
        {
            if (A[j] > A[Max])
            {
                Max = j;
            }
        }
        if (A[i] < A[Max])
        {
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i];
    }
}


*/