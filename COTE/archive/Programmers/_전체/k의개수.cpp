#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;

    for (int a = i; a <= j; a++) {
        int b = a;
        while (1) {
            if (b == 0) break;

            if (b % 10 == k) answer++;
            b /= 10;
        }
    }

    return answer;
}