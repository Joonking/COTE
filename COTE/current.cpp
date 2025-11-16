#include "utils/fileio.h"  // 제출 시 삭제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> trees(N);
    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
    }
    
    sort(trees.begin(), trees.end());
    
    int leftCut = 0;
    int rightCut = trees[N - 1];
    
    int answer = 0;  // 답 저장 변수 추가
    
    while (leftCut <=rightCut)
    {
        int mid = (leftCut + rightCut) / 2;
        long long sum = 0;
        for (int i : trees)
        {
            if (i-mid >0) sum += i-mid;
        }
 
        //나무들이 200, 300, 400 이런데 mid 값이 만약 1이야
        // 근데 M은 30이야. 30이면 충분해.
        //그러면 199 + 299 + 399 = sum >= 30 말도 안되게 낭비임.
        // 즉 문제는 나무를 최소로 잘라 최대의 값이 필요한거임. 
        // 그래서 답을 저장해 놓고 계속 left를 올려서 최적의 값을 찾는거임.
        if (sum >= M)
        {
            answer = mid;
            leftCut = mid + 1;
        }
        // sum < M 인 경우는 sum = 10 < M = 30 이런경우니까
        // 자르는 높이(mid)가 너무 높게 설정된거.
        // right를 조정해서 mid 값이 더 낮아질 수 있도록.
        else
        {
            rightCut = mid - 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
