#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;

    unordered_map<int, int> hash;

    for (int i : array)
    {
        hash[i]++;              //hash의 first : 숫자,   second : 개수
    }

    int MaxCount = 0;

    for (auto i : hash)
    {
        if (i.second > MaxCount)
        {
            answer = i.first;
            MaxCount = i.second;
        }
        else if (i.second == MaxCount)
        {
            answer = -1;
        }
    }

    return answer;
}