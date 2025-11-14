#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    queue<int> Queue;

    for (int i = 1; i <= N; i++)
    {
        Queue.push(i);
    }

    while (Queue.size() > 1)
    {
        Queue.pop();
        Queue.push(Queue.front());
        Queue.pop();
    }

    cout << Queue.front();

}