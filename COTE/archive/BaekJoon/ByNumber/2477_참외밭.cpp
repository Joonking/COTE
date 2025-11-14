#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, n, a;
    vector<pair<int, int>>v;
    cin >> k;
    int EW = 0;
    int NS = 0;
    for (int i = 0; i < 6; i++) {
        cin >> n >> a;
        v.push_back(make_pair(n, a));
        if (n >= 3) NS += a;
        else EW += a;
    }
    NS /= 2;    // 큰 정사각형의 위, 아래 변의 길이
    EW /= 2;    // 큰 정사각형의 왼쪽, 오른쪽 변의 길이
    int index = -1;
    bool check = false;
    for (int i = 0; i < 6; i++) {
        // 현재 인덱스가 잘리지 않은 변인지 판단
        if (v[i].second == NS || v[i].second == EW) {
            int k = i + 1;
            if (k > 5) k = 0; // 현재 index가 5, 즉 배열의 마지막이라면
            // 다음 index는 0이 되어야 한다.
            // 다음 인덱스도 잘리지 않은 변이라면 "찾았다!!"
            if (v[k].second == NS || v[k].second == EW) {
                index = k;
                break;
            }
        }
    }
    int x = index + 2;
    int y = index + 3;
    if (x > 5)x -= 6;
    if (y > 5)y -= 6;
    // (큰 정사각형의 넓이 - 작은 정사각형의 넓이) * k
    cout << ((NS * EW) - (v[x].second * v[y].second)) * k << "\n";
}
