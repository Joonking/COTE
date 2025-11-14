#include <iostream>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(int o1, int o2)
    {
        int first_abs = abs(o1);
        int second_abs = abs(o2);
        if (first_abs == second_abs)
        {
            //절대값이 같을때는 음수 우선 정렬
            return o1 > o2;
        }
        else
        {
            //절댓값을 기준으로 정렬
            return first_abs > second_abs;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //우선순위 큐 선언 방식 : <자료형, 구현체, 비교함수명>
    priority_queue<int, vector<int>, compare> P_Queue;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int request;
        cin >> request;

        if (request == 0)
        {
            if (P_Queue.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << P_Queue.top() << "\n";
                P_Queue.pop();
            }
        }
        else
        {
            P_Queue.push(request);
        }
    }
}



