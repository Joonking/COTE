#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#define MAX 10000

bool visited[10000];

int D(int n) { return (2 * n) % MAX; }
int S(int n) { return (n == 0) ? 9999 : n - 1; }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n / 10) + (n % 10) * 1000; }

string BFS(int a, int b) {
    queue<pair<int, string>> q;

    q.push({ a, "" });

    while (!q.empty()) {
        int now = q.front().first;
        string ans = q.front().second; q.pop();

        if (now == b) {
            return ans;
        }

        int next = D(now);
        if (!visited[next]) {
            q.push({ next, ans + "D" });
            visited[next] = true;
        }

        next = S(now);
        if (!visited[next]) {
            q.push({ next, ans + "S" });
            visited[next] = true;
        }

        next = L(now);
        if (!visited[next]) {
            q.push({ next, ans + "L" });
            visited[next] = true;
        }

        next = R(now);
        if (!visited[next]) {
            q.push({ next, ans + "R" });
            visited[next] = true;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        fill(visited, visited + MAX, false);
        cout << BFS(a, b) << endl;
    }
}