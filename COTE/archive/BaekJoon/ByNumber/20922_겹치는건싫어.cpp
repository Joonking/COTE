#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N : 수열 길이, K : 같은 정수를 K개 이하로 포함
int N, K;
vector<int> Nums;
int CheckList[100001] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    Nums.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> Nums[i];
    }

    int StartIndex = 0;
    int EndIndex = 0;

    int MaxLength = 0;

    while (EndIndex < N)
    {
        //추가할 숫자.
        int AddNum = Nums[EndIndex];

        //추가할 숫자가 K 개수 이하면
        if (CheckList[AddNum] < K)
        {
            //개수 늘려주고
            CheckList[Nums[EndIndex]]++;
            //End 인덱스 하나 늘리고
            EndIndex++;

            //윈도우 크기 제일 큰거 담기
            MaxLength = max(MaxLength, EndIndex - StartIndex);
        }
        //K 개수 이상이면
        else
        {
            //뺄 숫자 담고 StartIndex 하나 증가
            int SubNum = Nums[StartIndex++];
            CheckList[SubNum]--;
        }
    }

    cout << MaxLength;

    return 0;
}