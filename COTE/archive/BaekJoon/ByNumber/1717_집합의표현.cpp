//050_1717 집합 표현하기

#include <iostream>
#include <vector>
using namespace std;

void unionfunc(vector<int> &parent,int a, int b);
int find(vector<int>& parent, int a);
bool checkSame(vector<int>& parent, int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N : 원소의 개수, M : 질의 개수
    int N, M;
    cin >> N >> M;

    vector< int > parent(N+1);
    for (int i = 0; i < N + 1; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 0; i < M; i++)
    {
        int qustion, a, b;
        cin >> qustion >> a >> b;

        if (qustion == 0)
        {
            unionfunc(parent, a, b);
        }
        else
        {
            if (checkSame(parent, a, b))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
}

void unionfunc(vector<int>& parent, int a, int b)
{
    a = find(parent, a);
    b = find(parent, b);

    if (a != b)
        parent[b] = a;
}

int find(vector<int>& parent, int a)
{
    if (a == parent[a])
    {
        return a;
    }
    else
    {
        parent[a] = find(parent, parent[a]);
        return parent[a];
    }
}

bool checkSame(vector<int>& parent, int a, int b)
{
    a = find(parent, a);
    b = find(parent, b);

    return a == b;
}
