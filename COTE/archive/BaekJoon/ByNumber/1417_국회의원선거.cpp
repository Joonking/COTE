#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int Dasom;
    cin >> Dasom;

    priority_queue<int> PQ; // 최대 힙 사용

    // 후보자들의 득표 수 입력
    for (int i = 0; i < N - 1; i++)
    {
        int temp;
        cin >> temp;
        PQ.push(temp);
    }

    int Count = 0;

    while (true)
    {
        // 큐가 비어있으면 종료
        if (PQ.empty()) {
            cout << Count << "\n";
            return 0;
        }

        // 가장 높은 득표수 가져오기
        int Top = PQ.top();

        // Top이 다솜보다 크면
        if (Top >= Dasom)
        {
            PQ.pop(); // 최댓값 제거
            PQ.push(Top - 1); // 1 감소 후 다시 넣기
            Dasom++; // 다솜의 득표수 증가
            Count++; // 카운트 증가
        }
        else
        {
            // 만약 Top이 다솜보다 작으면 루프 종료
            cout << Count << "\n"; // 결과 출력
            return 0;
        }
    }

    return 0;
}
