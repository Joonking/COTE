#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";

    for (char s : rsp)
    {
        if (s == '0')
        {
            answer += '5';
        }
        if (s == '2')
        {
            answer += '0';
        }
        if (s == '5')
        {
            answer += '2';
        }
    }

    return answer;
}