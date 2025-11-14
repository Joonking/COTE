#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int n = 0, idx = 0;
    char c;

    for (int i = 0; i < my_string.size(); i++) {
        if (my_string[i] >= '0' && my_string[i] <= '9') {
            n = n * 10 + my_string[i] - '0';
        }

        else {
            idx = i;
            answer += n;
            n = 0;
            break;
        }
    }

    for (int i = idx + 1; i < my_string.size(); i++) {
        if (my_string[i] >= '0' && my_string[i] <= '9') {
            n = n * 10 + my_string[i] - '0';
        }

        else if (my_string[i] == '+') {
            c = '+';
        }

        else if (my_string[i] == '-') {
            c = '-';
        }

        else if (my_string[i] == ' ' && my_string[i - 1] >= '0' && my_string[i - 1] <= '9') {
            if (c == '+') answer += n;
            else answer -= n;
            n = 0;
        }
    }

    if (c == '+') answer += n;
    else answer -= n;

    return answer;
}