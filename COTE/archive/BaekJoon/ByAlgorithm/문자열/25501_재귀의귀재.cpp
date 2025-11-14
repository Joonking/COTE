#include <string>
#include<iostream>
#include<string.h>
using namespace std;

int iNum = 0;

int recursion(const char* s, int l, int r) {
    iNum++;
    if (l >= r)
    {
        return 1;
    }
    else if (s[l] != s[r]) return 0;
    else
    {
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main()
{
    int iTmp;
    string sInput;
    cin >> iTmp;
    for (int i = 0; i < iTmp; i++)
    {
        cin >> sInput;
        cout << isPalindrome(sInput.c_str()) << " " << iNum << endl;
        iNum = 0;
    }

}

