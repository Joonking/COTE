#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].second;
        cin >> A[i].first;
    }

    //종료시간(first)을 기준으로 sort
    //종료시간이 빠를수록 다음 회의와 겹치지 않게 시작하는데 유리함.
    sort(A.begin(), A.end());

    int count = 0;  //가능한 회의 개수
    int end = -1;  //전 회의시간의 종료시간

    for (int i = 0; i < N; i++)
    {
        //전 회의시간 종료시간보다 
        //현재 회의 시작 시간이 늦다면.
        if (A[i].second >= end)
        {
            //전회의 시간에 현재 회의시간의 종료 시간을 넣고
            end = A[i].first;
            //가능한 회의 개수 ++
            count++;
        }
    }

    cout << count << "\n";
}