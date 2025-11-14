#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> A(n + 2, 1);
    for (int i : lost)
        A[i]--;
    for (int i : reserve)
        A[i]++;

    for (int i = 1; i <= n; i++)
    {
        if (A[i] == 0)
        {
            if (A[i - 1] == 2)
            {
                A[i - 1]--;
                A[i]++;
            }
            else if (A[i + 1] == 2)
            {
                A[i + 1]--;
                A[i]++;
            }
        }
    }



    for (int i = 1; i <= n; i++)
    {
        if (A[i])
            answer++;
    }

    return answer;
}