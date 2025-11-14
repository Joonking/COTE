#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;

        int sum = 0;
        vector<int> divisors;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                sum += i;
                divisors.push_back(i);
            }
        }

        if (sum == n) {
            cout << n << " = ";
            for (int i = 0; i < divisors.size(); i++) {
                cout << divisors[i];
                if (i != divisors.size() - 1) cout << " + ";
            }
            cout << endl;
        }
        else {
            cout << n << " is NOT perfect." << endl;
        }
    }
    return 0;
}