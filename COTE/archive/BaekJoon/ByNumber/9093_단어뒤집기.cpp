#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string line;
        getline(cin, line);

        stack<char> stk;

        for (char ch : line)
        {
            if (ch == ' ')
            {
                while (stk.empty() == false)
                {
                    cout << stk.top();
                    stk.pop();
                }
                cout << ' ';
            }
            else
            {
                stk.push(ch);
            }
        }

        while (stk.empty() == false)
        {
            cout << stk.top();
            stk.pop();
        }
        cout << '\n';
    }

    return 0;
}

//
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <algorithm> // reverse
//
//using namespace std;
//
//int main() {
//    int T;
//    cin >> T;
//    //이 줄은 숫자만 읽고, 엔터는 남겨둠
//    //그래서 바로 getline() 쓰면 그 엔터(\n)를 읽어버려서 
//    // 빈 문자열이 s에 들어감.
//    cin.ignore(); // 여기 꼭 필요함!
//
//    while (T--) {
//        string s;
//        getline(cin, s);  // 문장 전체 입력 받기
//
//        stringstream SS(s); // 공백 기준으로 단어 분리
//        string Temp;
//
//        while (SS >> Temp) {
//            reverse(Temp.begin(), Temp.end()); // 단어 자체 뒤집기
//            cout << Temp << ' ';
//        }
//        cout << '\n'; // 줄 바꿈도 해줘야 함
//    }
//
//    return 0;
//}
