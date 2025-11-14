#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int parent[101];

// 유니온-파인드(Union-Find) 알고리즘
int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

// 간선을 저장하는 구조체
struct Edge {
    int from, to;
    double dist;
};

// 두 섬 간의 거리를 계산하는 함수
double calcDist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool compare(Edge a, Edge b) {
    return a.dist < b.dist;
}

int solution(vector<int> x, vector<int> y) {
    int answer = 0;

    vector<Edge> edges; // 모든 간선을 저장할 벡터
    int n = x.size();

    // 모든 간선을 계산하여 벡터에 저장
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = calcDist(x[i], y[i], x[j], y[j]);
            edges.push_back({ i, j, dist });
        }
    }

    // 간선을 거리의 오름차순으로 정렬
    sort(edges.begin(), edges.end(), compare);

    // 초기화: 각 섬의 부모 노드를 자신으로 설정
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Kruskal 알고리즘으로 최소 스패닝 트리 구하기
    for (int i = 0; i < edges.size(); i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        double dist = edges[i].dist;

        // 두 섬이 이미 연결되어 있으면 continue
        if (find(from) == find(to)) continue;

        // 두 섬을 연결하고, 현재 다리의 길이가 가장 긴 길이로 갱신
        merge(from, to);
        answer = max(answer, (int)ceil(dist));
    }

    return answer;
}

int main() {
    vector<int> x = { 1,2,6,8 };
    vector<int> y = { 1,2,5,7 };
    cout << solution(x, y) << endl; // 5

    x = { 1,2,4,2 };
    y = { 1,1,4,2 };
    cout << solution(x, y) << endl; // 3

    return 0;
}







