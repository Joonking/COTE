#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &list, vector<bool> &visited, int num)
{
    if (visited[num])
        return;
    visited[num] = true;
    for (int i : list[num])
    {
        if (!visited[i])
            DFS(list, visited, i);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> GraphList(N + 1);
    vector<bool> Visited(N + 1, false);

    for (int i = 1; i <= M; i++)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;
        GraphList[tempA].push_back(tempB);
        GraphList[tempB].push_back(tempA);
    }

    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!Visited[i])
        {
            DFS(GraphList, Visited, i);
            count++;
        }
            
    }
    
    cout << count;

}











