#include <iostream>

using namespace std;

//정수론 사용방식
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int E, S, M;
    cin >> E >> S >> M;

    int Count = 1;  // 시작값을 1로 설정

    while (true)
    {
        // Count % 15 == E, Count % 28 == S, Count % 19 == M 인 조건을 찾음
        if ((Count - E) % 15 == 0 && (Count - S) % 28 == 0 && (Count - M) % 19 == 0)
            break;

        Count++;
    }

    cout << Count;

    return 0;
}

//브루트포스로 푸는 방식
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int E, S, M;
//    cin >> E >> S >> M;
//
//    int Count = 0;
//    int NowE = 0, NowS = 0, NowM = 0;
//
//    while (true)
//    {
//        Count++;
//
//        NowE++;
//        NowS++;
//        NowM++;
//
//        if (NowE == 16) NowE = 1;
//        if (NowS == 29) NowS = 1;
//        if (NowM == 20) NowM = 1;
//
//        if (NowE == E && NowS == S && NowM == M)
//            break;
//    }
//
//    cout << Count;
//
//    return 0;
//}
