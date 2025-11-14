#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int a, b, c, d;
    a = x;
    b = h - y;
    c = w - x;
    d = y;

    int MIN = min(a, b);
    MIN = min(MIN, c);
    MIN = min(MIN, d);

    cout << MIN << endl;
}




