#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int Dy[4] = { -1, 1, 0, 0 };
int Dx[4] = { 0, 0, -1, 1 };

bool Visited[51][51] = { false };

int BFS(const vector<string>& StrList, int y, int x)
{
    int Count = 0;

    queue<pair<int, int>> Queue;
    Queue.push({ y, x });
    Visited[y][x] = true;

    while (Queue.empty() == false)
    {
        pair<int, int> Front = Queue.front();
        Queue.pop();
        Count++;

        for (int i = 0; i < 4; i++)
        {
            int TempY = Dy[i] + Front.first;
            int TempX = Dx[i] + Front.second;

            if (TempY < 0 || TempX < 0 || TempY >= StrList.size() || TempX >= StrList.size())
                continue;

            //방문배열도 false고 문자도 (y, x)의 문자랑 같은 애들만 계속 추가
            if (StrList[TempY][TempX] == StrList[y][x] && Visited[TempY][TempX] == false)
            {
                Visited[TempY][TempX] = true;
                Queue.push({ TempY, TempX });
            }
        }
    }

    return Count;
}

int solution(vector<string> board) {
    int answer = 0;

    int Size = board.size();

    //가로로
    for (int i = 0; i < Size; i++)
    {
        int Count = 0;
        for (int k = 0; k < Size; k++)
        {
            if (Visited[i][k] == false)
            {
                Count += BFS(board, i, k);
            }
        }
        answer = max(answer, Count);
        fill(&Visited[0][0], &Visited[50][51], false);
    }

    //세로로 탐색
    for (int i = 0; i < Size; i++)
    {
        int Count = 0;
        for (int k = 0; k < Size; k++)
        {
            if (Visited[k][i] == false)
            {
                Count += BFS(board, k, i);
            }
        }
        answer = max(answer, Count);
        fill(&Visited[0][0], &Visited[50][51], false);
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> board1 = {
        "ABBBBC",
        "AABAAC",
        "BCDDAC",
        "DCCDDE",
        "DCCEDE",
        "DDEEEB"
    };

    vector<string> board2 = {
        "DDCCC",
        "DBBBC",
        "DBABC",
        "DBBBC",
        "DDCCC",
    };

    fill(&Visited[0][0], &Visited[50][51], false);
    cout << "\nboard1 답 : " << solution(board1) << "\n";
    fill(&Visited[0][0], &Visited[50][51], false);
    cout << "\nboard2 답 : " << solution(board2) << "\n";

    return 0;
}