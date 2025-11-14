#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> People(N + 1);
    vector<int> Degree(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        People[A].push_back(B);
        Degree[B]++;
    }

    queue<int> Queue;
    for (int i = 1; i <= N; i++)
    {
        if (Degree[i] == 0)
            Queue.push(i);
    }

    while (Queue.empty() == false)
    {
        int Front = Queue.front();
        Queue.pop();
        cout << Front << " ";

        for (int i : People[Front])
        {
            Degree[i]--;
            if (Degree[i] == 0)
                Queue.push(i);
        }
    }

    return 0;
}