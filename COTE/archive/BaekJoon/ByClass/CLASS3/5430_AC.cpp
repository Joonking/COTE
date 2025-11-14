#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;

    cin >> t;
    while (t--) {
        string order, str;
        bool reverse = false, error = false;
        deque<int> dq;
        cin >> order;
        cin >> n;
        cin >> str;     //[1,2,3,4,52] 같은 문자열이 들어옴
        string s = "";

        //dp에 숫자들 넣어주기
        for (int i = 0; i < str.length(); i++) {

            if (isdigit(str[i])) {  //isdigit으로 숫자인지 판별
                s += str[i];    //s에 추가

            }
            else {      //숫자가 아닌 문자가 나오면 [ ] 또는 , 
                if (!s.empty()) {   //s에 숫자가 있으면
                    dq.push_back(stoi(s));  //dp에 추가
                    s = ""; //s 초기화
                }
            }
        }

        for (auto o : order) {
            if (o == 'R') {     //R이면 거꾸로 
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else {      //D이면 하나 출력
                if (dq.empty()) {   
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (reverse)            //R이 들어온 상태면
                    dq.pop_back();  //뒤에껄 출력
                else                        //R이 들어온 상태가 아니면
                    dq.pop_front();     //앞에껄 출력
            }
        }
        if (!error) {     
            cout << '[';
        }
        if (reverse && !dq.empty()) {       //거꾸로 상태면
            for (auto o = dq.rbegin(); o != dq.rend(); o++) {
                if (o == dq.rend() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        else if (!reverse && !dq.empty()) {     //거꾸로 상태가 아니면
            for (auto o = dq.begin(); o != dq.end(); o++) {
                if (o == dq.end() - 1)
                    cout << *o;
                else
                    cout << *o << ',';
            }
        }
        if (!error)
            cout << "]\n";

    }
}