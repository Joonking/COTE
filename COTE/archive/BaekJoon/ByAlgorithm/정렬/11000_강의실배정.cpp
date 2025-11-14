#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Lecture {
    int start, end;
};

int main() {
    int n;
    cin >> n;

    vector<Lecture> lectures(n);
    for (int i = 0; i < n; ++i) {
        cin >> lectures[i].start >> lectures[i].end;
    }

    // 시작 시간을 기준으로 강의 정렬
    sort(lectures.begin(), lectures.end(), [](Lecture a, Lecture b) {
        return a.start < b.start;
        });

    // 우선순위 큐(최소 힙)를 사용하여 종료 시간을 관리
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lectures[0].end); // 첫 강의의 종료 시간을 넣음

    for (int i = 1; i < n; ++i) {
        // 현재 강의 시작 시간이 가장 빨리 끝나는 강의보다 늦거나 같다면, 그 강의실을 사용 가능
        if (lectures[i].start >= pq.top()) {
            pq.pop();
        }
        // 새로운 강의의 종료 시간을 추가
        pq.push(lectures[i].end);
    }

    // 최종 힙의 크기가 필요한 강의실의 수
    cout << pq.size() << endl;

    return 0;
}
