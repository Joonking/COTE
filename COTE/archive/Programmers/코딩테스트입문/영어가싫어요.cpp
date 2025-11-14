#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;

    vector<string> nums = { "zero", "one", "two",
                           "three", "four", "five", "six",
                           "seven", "eight", "nine" };

    string temp;
    string strAnswer;
    for (char s : numbers) {
        temp += s;
        if (find(nums.begin(), nums.end(), temp) == nums.end()) // 존재하지 않을 때
            continue;
        else {
            int a = find(nums.begin(), nums.end(), temp) - nums.begin();
            strAnswer += to_string(a);
            temp.clear();
        }
    }

    answer = stoll(strAnswer); // strAnswer를 long long 형식으로 변환

    return answer;
}