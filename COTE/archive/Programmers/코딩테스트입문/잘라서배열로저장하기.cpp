#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int cnt = (my_str.size() - 1) / n + 1;
    int idx = 0;

    while (cnt--) {
        if (cnt == 0) answer.push_back(my_str.substr(idx));
        else answer.push_back(my_str.substr(idx, n));
        idx += n;
    }

    return answer;
}