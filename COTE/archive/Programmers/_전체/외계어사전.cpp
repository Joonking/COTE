#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;

    for (int i = 0; i < dic.size(); i++) {
        map<char, int> mp;
        int cnt = 0;

        for (int j = 0; j < dic[i].size(); j++)
            mp[dic[i][j]]++;

        if (mp.size() == spell.size()) {
            for (int j = 0; j < spell.size(); j++) {
                if (mp[spell[j][0]] == 1)
                    cnt++;
            }
        }

        if (cnt == spell.size()) return 1;
    }

    return answer;
}