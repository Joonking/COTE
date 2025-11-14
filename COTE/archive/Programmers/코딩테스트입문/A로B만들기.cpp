#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string before, string after) {
    int answer = 1;

    unordered_map<char, int> hash;

    for (char s : before)
    {
        hash[s]++;
    }
    for (char s : after)
    {
        hash[s]--;
    }

    for (auto i : hash)
    {
        if (i.second != 0)
            answer = 0;
    }

    return answer;
}


