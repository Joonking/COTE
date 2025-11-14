#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> Tree;
vector<bool> Visited;

int DeleteNode = 0;
int LeafNodeCount = 0;

void DFS(int Node)
{
    Visited[Node] = true;

    int CNode = 0; // 유효한 자식 노드의 개수

    for (int i : Tree[Node])
    {
        if (i != DeleteNode && !Visited[i]) // 삭제된 노드 및 이미 방문한 노드를 건너뜀
        {
            CNode++;
            DFS(i);
        }
    }

    if (CNode == 0) // 자식 노드가 없으면 리프 노드
        LeafNodeCount++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    Tree.resize(N);
    Visited.resize(N, false);

    int Root = 0;

    for (int i = 0; i < N; i++)
    {
        int Temp;
        cin >> Temp;

        if (Temp == -1)
            Root = i;
        else
        {
            // Temp와 i를 양방향으로 연결
            Tree[Temp].push_back(i);
            Tree[i].push_back(Temp);
        }
    }

    cin >> DeleteNode;

    if (DeleteNode == Root)
        cout << 0 << "\n"; // 루트 노드가 삭제되면 리프 노드는 없음
    else
    {
        DFS(Root);
        cout << LeafNodeCount << "\n";
    }

    return 0;
}