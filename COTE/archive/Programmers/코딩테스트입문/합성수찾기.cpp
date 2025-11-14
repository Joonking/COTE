#include <string>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i) == false)
            answer++;
    }


    return answer;
}