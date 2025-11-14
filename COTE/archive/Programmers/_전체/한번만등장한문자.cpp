#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";

    map<char, int> hash;

    for (char ch : s)
    {
        hash[ch]++;
    }

    for (auto i : hash)
    {
        if (i.second == 1)
            answer += i.first;
    }

    return answer;
}

