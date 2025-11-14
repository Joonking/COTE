#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;

    string StrNum = to_string(num);

    for (int i = 0; i < StrNum.size(); i++)
    {
        int temp = StrNum[i] - '0';
        if (temp == k)
        {
            answer = i + 1;
            break;
        }
        if (i == StrNum.size() - 1)
            answer = -1;
    }

    return answer;
}