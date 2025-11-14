//D[i]  : i번째 날부터 퇴사일까지 벌 수 있는 최대 수입
//D[i] = D[i+1]   -> 오늘 시작되는 상담을 했을때 퇴사일까지 끝나지 않는 경우
//D[i] = MAX(D[i+1], D[i+T[i]] + P[i] )   -> 오늘 시작되는 상담을 했을때 퇴사일 안에 끝나는 경우
//					ex> D[5] = Max(D[6], D[5 + T[5]] + P[5] )
//						 D[6]은 5일차의 일을 시작 안했을경우임. 이 경우와
//						 D[5 + T[5]] + P[5] 은 
//							5일차 일 했을때 끝나는 날의 수입에다가
//							    *  T[5] : 5일차 일이 걸리는 날 
//							P[5] : 5일차일을 했을때의 수입을 더한 경우와 비교
//						그러면 5일 차 일을 안하는게 이득인지 하는게 이득인지를 알 수 있음.


#include <iostream>
#include <vector>

using namespace std;

//D[i] : i번째 일 부터 N일까지 벌 수 있는 최대 값
vector<int> D;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    D.resize(N + 2);

    vector<int> Ti(N + 1);
    vector<int> Pi(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> Ti[i] >> Pi[i];
    }

    D[N + 1] = 0;  // N+1 마지막날은 퇴사날이니 0

    for (int i = N; i > 0; i--)
    {
        //남은 날보다 수행날짜가 더 많으면 할 수 없음
        if ((N + 1 - i) < Ti[i])
        {
            D[i] = D[i + 1];
        }
        else  //할 수 있으면
        {
            D[i] = max(D[i + 1], D[i + Ti[i]] + Pi[i]);
        }
    }

    cout << D[1];

    return 0;
}