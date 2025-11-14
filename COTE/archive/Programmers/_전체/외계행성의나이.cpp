#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";

    string Age = to_string(age);

    for (char s : Age)
    {
        answer += s + 'a' - '0';
    }

    return answer;
}