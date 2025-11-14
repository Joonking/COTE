#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    unordered_map<char, int> freq;  // 각 문자의 등장 횟수를 저장할 맵
    unordered_map<int, int> freqCount;  // 등장 횟수별 빈도를 저장할 맵

    // 각 문자의 등장 횟수를 구함
    for (char c : s) {
        freq[c]++;
    }

    // 등장 횟수들의 빈도를 저장함
    for (auto it : freq) {
        freqCount[it.second]++;
    }

    // 등장 횟수의 종류가 1개면 모든 문자의 등장 횟수가 동일 -> 유효함
    if (freqCount.size() == 1) {
        return "YES";
    }

    // 등장 횟수의 종류가 2개면 그 두 경우를 분석
    if (freqCount.size() == 2) {
        auto it = freqCount.begin();
        int firstFreq = it->first;
        int firstCount = it->second;
        ++it;
        int secondFreq = it->first;
        int secondCount = it->second;

        // 첫 번째 경우: 한 문자가 다른 문자보다 1회 더 많고, 그 문자의 빈도가 1개인 경우
        if ((firstFreq == 1 && firstCount == 1) || (secondFreq == 1 && secondCount == 1)) {
            return "YES";
        }
        // 두 번째 경우: 등장 횟수가 1 차이나고, 빈도가 1인 경우
        if ((abs(firstFreq - secondFreq) == 1) && (firstCount == 1 || secondCount == 1)) {
            return "YES";
        }
    }

    // 위의 두 경우가 아니라면 유효하지 않음
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
