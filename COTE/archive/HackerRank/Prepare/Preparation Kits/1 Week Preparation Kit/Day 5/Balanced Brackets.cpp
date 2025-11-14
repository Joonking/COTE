
//내 코드
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    stack<char> Stack;

    for (char c : s)
    {
        if (Stack.empty() == false)
        {
            if (c == '}')
            {
                if (Stack.top() == '{')
                {
                    Stack.pop();
                    continue;
                }
            }
            if (c == ')')
            {
                if (Stack.top() == '(')
                {
                    Stack.pop();
                    continue;
                }
            }
            if (c == ']')
            {
                if (Stack.top() == '[')
                {
                    Stack.pop();
                    continue;
                }
            }
        }
        Stack.push(c);
    }
    if (Stack.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}



//지피티 코드
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//string isBalanced(string s) {
//    stack<char> Stack;
//
//    for (char c : s) {
//        if (c == '{' || c == '(' || c == '[') {
//            Stack.push(c);  // 여는 괄호는 스택에 push
//        }
//        else {
//            if (Stack.empty()) {
//                return "NO";  // 스택이 비어 있으면 잘못된 괄호
//            }
//            char top = Stack.top();
//            if ((c == '}' && top == '{') ||
//                (c == ')' && top == '(') ||
//                (c == ']' && top == '[')) {
//                Stack.pop();  // 올바른 쌍이 맞으면 pop
//            }
//            else {
//                return "NO";  // 쌍이 맞지 않으면 NO
//            }
//        }
//    }
//
//    return Stack.empty() ? "YES" : "NO";  // 스택이 비어 있으면 YES
//}