#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string my_string) {
    string answer = "";

    unordered_map<char, int> hash;

    for (char s : my_string)
    {
        if (hash.find(s) == hash.end())
        {
            hash[s] = 1;
            answer += s;
        }
    }

    return answer;
}