#include <string>
#include <vector>
using namespace std;

vector<bool> Visited;

void DFS(vector<vector<int>>& list, int num)
{
    if (Visited[num])
        return;
    Visited[num] = true;

    for (int i : list[num])
    {
        if (!Visited[i])
            DFS(list, i);
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    Visited = vector<bool>(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!Visited[i])
        {
            answer++;
            DFS(computers, i);
        }
    }

    return answer;
}