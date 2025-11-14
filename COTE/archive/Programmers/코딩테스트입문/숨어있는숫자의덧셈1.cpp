#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;

    for (char s : my_string)
    {
        if (s > '0' && s <= '9')
            answer += s - '0';
    }

    return answer;
}