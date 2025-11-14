#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> v(emergency);

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < emergency.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[j] == emergency[i]) answer.push_back(j + 1);
        }
    }

    return answer;
}