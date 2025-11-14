#include<iostream>

using namespace std;

//재귀 이용.
int Factorial(int num) {
    if (num == 1 || num == 0) {
        return 1;

    }
    else {
        return Factorial(num - 1) * num;
    }

}

int main(void) {

    int n, k;

    cin >> n >> k;

    cout << Factorial(n) / (Factorial(k) * Factorial(n - k));

    return 0;
}
