#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> nums;  // 입력으로 주어진 그래프의 인접 리스트
vector<vector<int>> answer;  // 경로 정보를 저장할 2차원 벡터

void BFS(int start)
{
    vector<bool> visited(N, false);  // 방문한 노드 체크용 배열, 기본값은 false로 초기화
    queue<int> Queue;
    Queue.push(start);
    while (!Queue.empty())
    {
        int now = Queue.front();  // 큐에서 현재 노드를 꺼냄
        Queue.pop();
        for (int i : nums[now])  // 현재 노드와 연결된 노드들을 탐색
        {
            if (!visited[i])  // 방문하지 않은 노드인 경우에만 처리
            {
                answer[start][i] = 1;  // 경로가 존재하는 경우를 표시
                visited[i] = true;  // 해당 노드를 방문했다고 표시
                Queue.push(i);  // 큐에 추가하여 탐색 계속
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;  // 노드의 개수 입력

    nums.resize(N);  // 인접 리스트 크기 설정
    answer.resize(N, vector<int>(N, 0));  // 경로 정보를 저장할 2차원 벡터 초기화 (0으로)

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                nums[i].push_back(k);  // 그래프의 연결 정보를 인접 리스트에 저장
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        BFS(i);  // 모든 노드에 대해 BFS 수행하여 경로 정보 계산
    }

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cout << answer[i][k] << " ";  // 경로 정보 출력
        }
        cout << "\n";
    }

    return 0;
}
