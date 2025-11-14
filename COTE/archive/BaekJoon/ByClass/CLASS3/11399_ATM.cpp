#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int time[n];
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    sort(time, time + n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (n - i) * time[i];
    }

    cout << sum << endl;

    return 0;
}