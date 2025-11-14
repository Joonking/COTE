#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;

    for (char s : my_string)
    {
        if (s >= '0' && s <= '9')
            answer.push_back(s - '0');
    }
    sort(answer.begin(), answer.end());

    return answer;
}