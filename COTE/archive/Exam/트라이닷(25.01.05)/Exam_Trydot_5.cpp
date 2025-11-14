/*
문제 5번

한 번에 최대 N 잔까지 동시에 커피를 추출할 수 있는 커피 추출기가 있습니다. 
이 커피 추출기를 이용해 커피를 만들 때, 커피가 만들어지는 순서를 구하려 합니다.
만들어야 하는 커피가 M잔이면, 커피에 1부터 M까지 순서대로 주문번호가 붙어있습니다.
또, 주문번호 순으로 빈 커피 추출구에서 커피를 만들기 시작합니다. 
만약 빈 추출구가 없다면, 빈 추출구가 생길 때까지 다음 주문은 잠시 기다리며, 
빈 추출구가 생기면 대기 중인 다음 커피 를 즉시 만들기 시작합니다.
모든 커피는 만드는데 일정 시간이 소요되는데, 
소요 시간은 커피 종류별로 다를 수 있습니다. 
따라서 커피 제조 시간에 따라 각 주문이 완료 되는 순서는 다를 수 있습니다.
커피 추출구 개수 N, 각 커피를 만드는데 걸리는 시간이 주문번호 순서대로 
담긴 배열 coffee_times가 매개변수로 주어질 때, 커피가 완성되 는 순서대로 
주문번호를 배열에 담아 return 하도록 solution 함수를 완성해주세요.
단, 커피 주문이 추출구에 배정되는데 걸리는 시간은 없다고 가정하며, 
커피 추출이 동시에 완료됐을 경우 작은 주문번호가 앞에 오도록 하면 됩니다.

제한사항
• N은 1 이상 10,000 이하인 자연수입니다.
• coffee_times의 길이는 1이상 300,000 이하입니다.
• coffee_times의 원소는 1 이상 100,000,000 이하인 자연수입니다.

입출력 예
N          coffee_times            result
3           [4, 2, 2, 5, 3]           [2, 3, 1, 5, 4]
1           [100, 1, 50, 1, 1]      [1, 2, 3, 4, 5]

설명
입출력 예 #1
커피 추출구 개수N=3이고, 
커피별 제조시간은 주문 번호 순서대로 [4초, 2초, 2초, 5초, 3초]입니다.

시간(초)       제작중 커피(주문번호)        완료 순서
0                 [1번, 2번, 3번]                  
1                 [1번, 2번, 3번]
2                 [1번, 4번, 5번]                  [2번, 3번]
3                 [1번, 4번, 5번]                  [2번, 3번]
4                 [4번, 5번]                        [2번, 3번, 1번]
5                 [4번]                              [2번, 3번, 1번, 5번]
6                 [4번]                              [2번, 3번, 1번, 5번]
7                 0                                   [2번, 3번, 1번, 5번, 4번]
1 

빈 추출구 3곳에 1, 2, 3번 주문이 동시에 배정됩니다.
• 2초가 지나면 2, 3번 커피가 다 만들어지고, 빈 추출구에 4, 5번 주문이 배정됩니다.
• 4초가 지나면 1번 커피가 완료되며, 5번 주문이 배정됩니다.
• 배정 후 3초가 지난 5초에 5번 주문이 완료됩니다.
• 배정 후 5초가 지난 7초에 4번 주문이 완료됩니다.
따라서 [2, 3, 1, 5, 4]를 return 하면 됩니다.

입출력 예 #2
커피 추출구 개수 N=1이므로, 한 번에 한 잔씩 커피를 만들 수 있습니다. 
따라서 커피는 주문번호 순서대로 완성됩니다.

해결 전략
우선순위 큐를 사용한 추출기 관리:
각 추출기의 상태를 관리하며, 가장 빨리 커피를 만들 수 있는 추출기를 선택합니다.
우선순위 큐를 사용하여 현재 시간 기준으로 추출기를 정렬합니다.

주문 순서 처리:
주문을 순차적으로 처리하며, 우선순위 큐에서 가장 빨리 커피를 만들 수 있는 추출기에 할당합니다.

결과 저장:
주문 번호를 추출이 완료된 순서대로 결과에 저장합니다.
*/



#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Machine {
    long long EndTime;
    int Index;

    bool operator<(const Machine& other) const
    {
        //끝나는 시간이 동일하면 인덱스가 작은 순서로
        if (EndTime == other.EndTime) return Index > other.Index;
        //끝나는 시간이 작은 순서로
        return EndTime > other.EndTime;
    }
};


vector<int> solution(int N, vector<int> coffee_times) {
    vector<int> answer;

    priority_queue<Machine> PQ;

    for (int i = 0; i < min(N, (int)coffee_times.size()); ++i)
    {
        PQ.push({ coffee_times[i], i + 1 });
    }

    //현재 까지 만들어진 커피 개수
    int CurrentOrder = N;

    while (PQ.empty() == false)
    {
        Machine Current = PQ.top();
        PQ.pop();
        answer.push_back(Current.Index);

        //주문 들어간 수가 만들어야 할 커피 개수보다 작다면 (아직 만들 커피가 더 있으면)
        if (CurrentOrder < coffee_times.size())
        {
            
            //현재 제일 빨리 끝나는 커피 머신에 있는 커피 만들어지는 시간 + 다음 만들어질 커피 시간을 더해서 추가함.
            //인덱스는 현재 주문수 + 1
            PQ.push({ Current.EndTime + coffee_times[CurrentOrder], CurrentOrder + 1 });
            ++CurrentOrder;
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 3;

    vector<int> CoffeeTimes = {4, 2, 2, 5, 3};

    vector<int> Result = solution(3, CoffeeTimes);
    
    for (int i : Result)
    {
        cout << i << " ";
    }

    return 0;
}