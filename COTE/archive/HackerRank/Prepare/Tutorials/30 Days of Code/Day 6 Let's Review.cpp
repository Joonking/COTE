#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string StrTemp;
        cin >> StrTemp;
        string Str1, Str2;

        for (int k = 0; k < StrTemp.size(); k++)
        {
            if (k % 2 == 0)
                Str1 += StrTemp[k];
            else
                Str2 += StrTemp[k];
        }
        cout << Str1 << " " << Str2 << "\n";
    }

    return 0;
}
