#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
vector<vector<int>> forwardList, backwardList;
vector<int> inDegree, outDegree;

int bfs(const vector<vector<int>>& graph, vector<int>& degree) {
    vector<bool> visited(N + 1, false);
    queue<int> Queue;
    int count = 0;

    Queue.push(X);
    visited[X] = true;

    while (!Queue.empty()) {
        int current = Queue.front();
        Queue.pop();

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                Queue.push(next);
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> X;

    forwardList.resize(N + 1);
    backwardList.resize(N + 1);
    inDegree.resize(N + 1, 0);
    outDegree.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        forwardList[A].push_back(B);
        backwardList[B].push_back(A);
        outDegree[A]++;
        inDegree[B]++;
    }

    // X에서 도달 가능한 노드 수 (앞방향 그래프)
    int higherRankCount = bfs(forwardList, outDegree);

    // X에 도달할 수 있는 노드 수 (뒤방향 그래프)
    int lowerRankCount = bfs(backwardList, inDegree);

    cout << lowerRankCount + 1 << " " << N - higherRankCount << "\n";

    return 0;
}
