#include <iostream>
#include <vector>

using namespace std;

// 도시 별 도로의 길이
vector<long long> road;

// 도시 별 주유 가격
vector<long long> oil;

// 최소 누적 비용
long long total_oil_cost;

// 제일 왼쪽 도시에서 제일 오른쪽 도시로 가는, 최소 비용 계산
long long greedy() {

    // 우선, 첫 번째 도시의 주유 비용을 최소 주유 비용으로 지정
    long long min_oil_cost = oil[0];

    // 첫 번째 도시에서 두 번째 도시로 갈때에는, 반드시 첫 번째 도시에서 주유
    // 따라서, 두 번째 도시까지는 주유를 마친 상태
    total_oil_cost += oil[0] * road[0];

    // 두 번째 도시부터 제일 오른쪽 도시까지, 도시 별 주유 가격을 확인
    for (int i = 1; i < oil.size() - 1; ++i) {

        // i 번째 도시의 주유 가격이, 현재까지의 최소 주유 비용보다 비싸다면, 
        if (oil[i] > min_oil_cost) {
            // 현재까지의 최소 주유 비용으로, i+1 번째 도시까지 이동할 수 있도록 주유
            total_oil_cost += min_oil_cost * road[i];
        }

        // i 번째 도시의 주유 가격이, 현재까지의 최소 주유 비용보다 싸다면, 
        else {
            // i 번째 도시의 주유 가격을, 최소 주유 비용으로 변경한 뒤,
            min_oil_cost = oil[i];
            // 최소 주유 비용으로, i+1 번째 도시까지 이동할 수 있도록 주유
            total_oil_cost += min_oil_cost * road[i];
        }
    }

    // 최소 누적 비용 반환
    return total_oil_cost;
}

int main() {

    // 도시 개수
    int n;
    cin >> n;

    // 도시 별 도로의 길이
    for (int i = 0; i < n - 1; ++i) {
        long long road_len;
        cin >> road_len;
        road.push_back(road_len);
    }

    // 도시 별 주유 가격
    for (int i = 0; i < n; ++i) {
        long long oil_cost;
        cin >> oil_cost;
        oil.push_back(oil_cost);
    }

    // 제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소 비용 계산
    cout << greedy() << endl;

}