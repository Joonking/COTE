#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";

    for (char s : my_string)
    {
        if (islower(s))
            answer += toupper(s);
        else
            answer += tolower(s);
    }

    return answer;
}