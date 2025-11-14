#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    int a[26] = { 0 }, M=0,t, B=0;

    cin >> s;

    for (char c : s)
    {
        if (c > 96) 
            a[c - 97]++;
        else
            a[c - 65]++;
    }

    for (int i=0; i < 26; i++)
    {
        if (a[i] > M)
            M = a[i];
    }

    for (int i=0; i < 26; i++)
    {
        if (a[i] == M)
        {
            t = i;
            B++;
        }
    }

    if (B > 1)
        cout << "?";
    else
        cout << char(65 + t);
}