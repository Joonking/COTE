//052_1043 거짓말쟁이가 되긴 싫어

#include <iostream>
#include <vector>

using namespace std;

static  vector<int> parent;
static  vector<int> trueP;
static vector < vector <int> > party;
static int result;

void unionfunc(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //N : 사람수, M : 파티 수, T : 진실을 아는 사람 수
    int N, M, T;
    cin >> N >> M >> T;
    trueP.resize(T);

    for (int i = 0; i < T; i++) //진실을 아는 사람 저장
        cin >> trueP[i];

    party.resize(M);

    for(int i=0;i<M;i++)  //파티 데이터 저장
    {
        int party_size;
        cin >> party_size;
        for(int j=0;j<party_size;j++)
        {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) { // 대표 노드를 자기 자신으로 초기화 하기
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) { // 각 파티에 참여한 사람들을 하나의 그룹으로 만들기 -> union 연산
        int firstPeople = party[i][0];   //파티의 첫번째 사람을 기준으로
        for (int j = 1; j < party[i].size(); j++) {
            unionfunc(firstPeople, party[i][j]);   //유니온
        }
    }

    for (int i = 0; i < M; i++) { // 각 파티에서 진실을 아는 사람과 같은 그룹에 있다면 과장 할 수 없음
        bool isPossible = true;
        int cur = party[i][0];  //각 파티의 첫번째 사람만 보면됨. 
        for (int j = 0; j < T; j++) {  //진실을 아는 사람 수 만큼 for
            if (find(cur) == find(trueP[j])) {   //파티 첫번째 사람의 대표와 진실을 하는 사람이 같다면
                isPossible = false; 
                break;
            }
        }
        if (isPossible)
            result++;
    }
    cout << result;
}

void unionfunc(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a!=b)
    {
        parent[b] = a;
    }

}

int find(int a)
{
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);
}
