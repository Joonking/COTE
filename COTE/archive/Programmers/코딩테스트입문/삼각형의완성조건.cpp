#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    unordered_set<int> intSet;
    sort(sides.begin(), sides.end());

    // sides[2]이 max일 때
    for (int i = sides[1]; i < sides[0] + sides[1]; i++) {
        if (sides[0] + sides[1] > i) {
            intSet.insert(i);
        }
    }

    // sides[1]이 max일 때
    for (int i = 1; i < sides[1]; i++) {
        if (sides[0] + i > sides[1]) {
            intSet.insert(i);
        }
    }

    answer = intSet.size();
    return answer;
}