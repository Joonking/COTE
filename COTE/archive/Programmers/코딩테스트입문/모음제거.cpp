#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";

    for (char s : my_string)
    {
        if (s != 'a' && s != 'e' && s != 'i' && s != 'o' && s != 'u')
            answer += s;
    }

    return answer;
}