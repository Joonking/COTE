//051_1976 여행 계획 짜기

#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent;

void unionfunc(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N : 도시의 개수, M : 여행 경로 데이터
    int N, M;
    cin >> N >> M;

    int dosi[201][201]; //도시 데이터

    for (int i = 1; i <= N; i++) { 	// 도시 연결 데이터 저장
        for (int j = 1; j <= N; j++) {
            cin >> dosi[i][j];
        }
    }

    int route[1001]; //여행계획 데이터
    for (int i = 1; i <= M; i++) { 	//여행 도시 정보 저장
        cin >> route[i];
    }

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) { 	// 대표 노드를 자기 자신으로 초기화
        parent[i] = i;
    }

    // 인접행렬 탐색에서 도시가 연결되어 있으면 유니온 실행
    for (int i = 1; i <= N; i++) { 
        for (int j = 1; j <= N; j++) {
            if (dosi[i][j] == 1) unionfunc(i, j);
        }
    }

    // 여행 계획 도시들이 하나의 대표 도시로 연결되어 있는지 확인
    int index = find(route[1]);   //첫번째 여행 도시의 대표를 index에 넣고
    bool connect = true;
    for (int i = 2; i <= M; i++) {  //여행할 도시 M개 돌리기
        if (index != find(route[i])) {     //경로에 있는 도시의 대표가 첫번째 도시의 대표랑 다르다면
            cout << "NO" << "\n";  //no 출력하고 끝내기
            connect = false;
            break;
        }
    }
    if (connect) cout << "YES" << "\n";


}

void unionfunc(int a, int b)
{
    a = find(a);   //a의 대표
    b = find(b);   //b의 대표를 우선 찾아서
    if (a != b)     //두 대표가 다르면 b한테 a의 대표를 넣어줌.
        parent[b] = a;

}

int find(int a)
{
    if (a == parent[a])  //자신과 대표가 같으면 자신을 리턴
        return a;
    else
        return parent[a] = find(parent[a]);

}
