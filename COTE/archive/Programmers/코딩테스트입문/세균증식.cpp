#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    int answer = 0;

    for (int i = 0; i < t; i++)
    {
        n *= 2;
    }

    answer = n;

    return answer;
}