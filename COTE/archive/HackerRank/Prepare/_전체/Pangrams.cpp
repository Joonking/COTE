#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    int Alpabets[26] = { 0 };
    for (char c : s)
    {
        Alpabets[tolower(c) - 'a']++;
    }
    string Ans = "";
    for (int i : Alpabets)
    {
        if (i == 0)
        {
            Ans = "not pangram";
            return Ans;
        }
    }
    Ans = "pangram";
    return Ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
