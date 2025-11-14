#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> psum(n + 1);
    for (int i = 0; i < n; i++) {
        psum[i + 1] = (psum[i] + a[i]) % m;
    }

    vector<long long> cnt(m, 0);
    for (int i = 0; i <= n; i++) {
        cnt[psum[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
    }

    cout << ans << '\n';

    return 0;
}