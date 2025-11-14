#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = 1;
    int sum = 1;

    while (1) {
        sum *= a;
        if (sum > n) break;
        a++;
    }

    a--;

    return a;
}