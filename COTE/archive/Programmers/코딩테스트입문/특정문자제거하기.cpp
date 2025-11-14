#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";

    for (char s : my_string)
    {
        if (s != letter[0])
            answer += s;
    }


    return answer;
}