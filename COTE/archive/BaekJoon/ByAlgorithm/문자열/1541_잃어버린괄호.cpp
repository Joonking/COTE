#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//문자열을 특정 구분자로 잘라 벡터에 저장하는 함수
vector<string> split(string input, char delimiter)
{
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter))
    {
        result.push_back(splitdata);
    }
    return result;
}

//나뉜 그룹의 더하기 연산 수행 함수
int mySum(string a)
{
    int sum = 0;
    vector<string> temp = split(a, '+');

    for (int i = 0; i < temp.size(); i++)
    {
        sum += stoi(temp[i]);  //string을 int로 변환
    }
    return sum;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    vector<string> A = split(str, '-');

    int answer = 0;

    for (int i = 0; i < A.size(); i++)
    {
        int temp = mySum(A[i]);
        if (i == 0)
            answer += temp;
        else
            answer -= temp;
    }

    cout << answer << "\n";
}