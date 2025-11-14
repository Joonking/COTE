#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> SNS;          // 친구 관계 부모 정보
unordered_map<string, int> networkSize;     // 네트워크 크기 정보

string FindFunction(string a)
{
    if (SNS[a] == a)
        return a;
    return SNS[a] = FindFunction(SNS[a]);  // 경로 압축
}

void UnionFunction(string a, string b)
{
    a = FindFunction(a);
    b = FindFunction(b);

    if (a != b)
    {
        SNS[b] = a;                      // b의 부모를 a로 갱신
        networkSize[a] += networkSize[b]; // a에 b의 네트워크 크기 추가
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int F;
        cin >> F;
        SNS.clear();
        networkSize.clear();

        for (int k = 0; k < F; k++)
        {
            string A, B;
            cin >> A >> B;

            if (SNS.find(A) == SNS.end())
            {
                SNS[A] = A;           // A 자신을 부모로 설정
                networkSize[A] = 1;   // 처음 시작할 때 A의 네트워크 크기는 1
            }
            if (SNS.find(B) == SNS.end())
            {
                SNS[B] = B;           // B 자신을 부모로 설정
                networkSize[B] = 1;   // 처음 시작할 때 B의 네트워크 크기는 1
            }

            UnionFunction(A, B);
            cout << networkSize[FindFunction(A)] << "\n";  // 합친 후 네트워크 크기를 출력
        }
    }

    return 0;
}
