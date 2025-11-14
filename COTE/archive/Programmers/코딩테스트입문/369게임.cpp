#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;

    string StrOrder = to_string(order);

    for (char s : StrOrder)
    {
        int temp = s - '0';
        if (temp == 3 || temp == 6 || temp == 9)
            answer++;
    }

    return answer;
}