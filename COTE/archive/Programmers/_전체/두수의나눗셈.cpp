#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    float temp = (float)num1 / (float)num2 * 1000;
    int answer = (int)temp;
    return answer;
}