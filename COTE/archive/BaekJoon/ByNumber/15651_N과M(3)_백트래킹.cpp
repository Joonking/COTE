#include "utils/fileio.h"  // 제출 시 삭제

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[10] = {0};

void solve(int num, int depth)
{
    arr[depth] = num;
    
    if (depth+1 == M)
    {
        for (int i=0;i<M;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i=1;i<=N;i++)
    {
        solve(i, depth+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    
    for (int i=1;i<=N;i++)
    {
        solve(i,0);
    }

    return 0;
}