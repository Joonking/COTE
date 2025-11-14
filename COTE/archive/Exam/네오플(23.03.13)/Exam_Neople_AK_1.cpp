#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int Pan[101][101] = { 0 };

int solution(int N, vector<vector<int>> facility) {

    int answer = INT_MAX;

    for (const auto& a : facility)
    {
        int Row = a[0];
        int Col = a[1];
        int Cost = a[2];

        for (int i = 1; i <= N; i++)
        {
            for (int k = 1; k <= N; k++)
            {
                int Sum = (abs(Row - i) + abs(Col - k)) * Cost;
                Pan[i][k] = max(Pan[i][k], Sum);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= N; k++)
        {
            answer = min(answer, Pan[i][k]);
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> Facility = { {1,3,2},{3,1,1} };

    cout << solution(N, Facility);

    cout << "\n\nPan 배열\n";
    for (int i = 0; i <= N; i++)
    {
        for (int k = 0; k <= N; k++)
        {
            cout << Pan[i][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}