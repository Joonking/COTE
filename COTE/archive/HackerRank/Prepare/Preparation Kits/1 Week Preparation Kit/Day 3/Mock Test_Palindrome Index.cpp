#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int palindromeIndex(string s) {

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // 왼쪽 문자를 제거했을 때 팰린드롬이 되는지 확인
            if (isPalindrome(s, left + 1, right)) {
                return left;
            }
            // 오른쪽 문자를 제거했을 때 팰린드롬이 되는지 확인
            if (isPalindrome(s, left, right - 1)) {
                return right;
            }
            // 둘 다 팰린드롬이 되지 않으면 -1 반환
            return -1;
        }
        left++;
        right--;
    }

    // 이미 팰린드롬인 경우 -1 반환
    return -1;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

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
