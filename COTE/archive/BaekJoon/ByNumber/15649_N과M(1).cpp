#include <iostream>
#include <vector>
using namespace std;

// 백트래킹 (Backtracking)
// 핵심 3단계: 선택(Choice) → 탐색(Explore) → 복구(Undo)
//
// 문제: 1~N 중에서 중복 없이 M개를 고른 수열 출력
//
// 사고 과정 (트리 구조):
//           시작
//      /     |     \
//     1      2      3     ← 첫 번째 선택
//    / \    / \    / \
//   2   3  1   3  1   2   ← 두 번째 선택 (이미 선택한 숫자 제외)
//
// visited 배열: 이미 사용한 숫자 체크
// arr 배열: 선택한 숫자를 순서대로 저장
// depth: 현재까지 선택한 개수

void solve(int* arr, bool* visited,int N, int M, int depth)
{
    if (depth == M)
    {
        for (int i=0;i<M;i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i=1;i<=N;i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        arr[depth] = i;
        solve(arr, visited, N, M, depth + 1);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int arr[10] = {0};
    bool visited[10] = {false};

    solve(arr, visited, N, M, 0);

    return 0;
}
