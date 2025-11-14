#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first;      //pair 첫번째 값 : 값
        v[i].second = i;      //pair 두번째 값: 정렬전 인덱스
    }

    sort(v.begin(), v.end());

    int max = 0;

    for (int i = 0; i < N; i++)
    {
        if (v[i].second - i > max)
            max = v[i].second - i;
    }

    cout << max + 1;
}