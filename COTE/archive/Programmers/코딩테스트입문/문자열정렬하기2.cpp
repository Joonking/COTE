#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";

    vector<char> arr;
    for (char s : my_string)
    {
        arr.push_back(tolower(s));
    }

    sort(arr.begin(), arr.end());

    for (char s : arr)
    {
        answer += s;
    }

    return answer;
}