#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

long closestSquaredDistance(vector<int>& x, vector<int>& y, int k) {
    vector<long> distances;
    int n = x.size();

    // 모든 점 쌍 간의 거리를 계산
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long dx = (long)x[i] - x[j];
            long dy = (long)y[i] - y[j];
            long dist = dx * dx + dy * dy;
            distances.push_back(dist);
        }
    }

    sort(distances.begin(), distances.end());

    // K번째로 가까운 거리 반환
    return distances[k-1];
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    vector<int> all_numbers;
    int val;
    while (input >> val) {
        all_numbers.push_back(val);
    }

    int k = all_numbers[0];  // 첫 번째 숫자는 K값
    int n = (all_numbers.size() - 1) / 2;  // 나머지 숫자들로 점의 개수 계산

    vector<int> x(n), y(n);

    // x 좌표들 읽기
    for (int i = 0; i < n; i++) {
        x[i] = all_numbers[1 + i];
    }

    // y 좌표들 읽기
    for (int i = 0; i < n; i++) {
        y[i] = all_numbers[1 + n + i];
    }

    long result = closestSquaredDistance(x, y, k);
    output << result << endl;

    input.close();
    output.close();

    return 0;
}