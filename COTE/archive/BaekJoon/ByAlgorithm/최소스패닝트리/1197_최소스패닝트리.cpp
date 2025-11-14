#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 유니온 파인드에 사용할 대표 노드 저장 배열
vector<int> Parent;

struct Edge {
    int Start, End, Cost;
    Edge(int S, int E, int C) : Start(S), End(E), Cost(C) {}

    // 우선순위 큐에서 오름차순 정렬을 위한 연산자
    bool operator> (const Edge& other) const {
        return Cost > other.Cost;
    }
};

// Find 함수: 경로 압축 최적화
int FindFunction(int Num) {
    if (Parent[Num] == Num)
        return Num;
    return Parent[Num] = FindFunction(Parent[Num]);
}

// Union 함수
void UnionFunction(int A, int B) {
    A = FindFunction(A);
    B = FindFunction(B);
    if (A != B) {
        Parent[B] = A; // B의 대표를 A로 갱신
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 우선순위 큐 (오름차순 정렬)
    priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;

    // 대표 노드 초기화
    Parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        Parent[i] = i;
    }

    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int Start, End, Cost;
        cin >> Start >> End >> Cost;
        PQ.push(Edge(Start, End, Cost));
    }

    int Result = 0; // MST의 가중치 합
    int EdgeCount = 0; // 현재 추가된 간선의 개수

    // 크루스칼 알고리즘
    while (!PQ.empty() && EdgeCount < N - 1) {
        int StartNode = PQ.top().Start;
        int EndNode = PQ.top().End;
        int Cost = PQ.top().Cost;
        PQ.pop();

        // 서로 다른 집합에 속하면 MST에 포함
        if (FindFunction(StartNode) != FindFunction(EndNode)) {
            UnionFunction(StartNode, EndNode);
            Result += Cost;
            EdgeCount++;
        }
    }

    // 출력 MST의 가중치 합
    cout << Result;

    return 0;
}
