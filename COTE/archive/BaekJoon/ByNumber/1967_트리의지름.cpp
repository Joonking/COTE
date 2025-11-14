#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> Tree;
vector<bool> Visited;

int MaxDistance = 0, MaxNode = 0;

void DFS(int Node, int Distance) 
{
    Visited[Node] = true;

    if (Distance > MaxDistance) {
        MaxDistance = Distance;
        MaxNode = Node;
    }

    for (auto& neighbor : Tree[Node]) {
        if (!Visited[neighbor.first]) {
            DFS(neighbor.first, Distance + neighbor.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Tree.resize(N + 1);
    Visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) 
    {
        int Parent, Child, Distance;
        cin >> Parent >> Child >> Distance;
        Tree[Parent].push_back({ Child, Distance });
        Tree[Child].push_back({ Parent, Distance });  // 양방향으로 추가
    }

    //가장 먼 노드 찾기
    MaxDistance = 0;
    DFS(1, 0);

    //위에서 찾은 가장 먼 노드에서 다시 가장 먼 노드 찾기
    fill(Visited.begin(), Visited.end(), false);
    MaxDistance = 0;
    DFS(MaxNode, 0);

    cout << MaxDistance << "\n";

    return 0;
}
