#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";

    for (char s : my_string)
    {
        for (int i = 0; i < n; i++)
            answer += s;
    }

    return answer;
}