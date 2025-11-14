#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string Hour = s.substr(0, 2);
    string AMPM = s.substr(8, 2);

    if (AMPM == "AM")
    {
        if (Hour == "12")
        {
            Hour = "00";
        }
    }
    else if (AMPM == "PM")
    {
        if (Hour != "12")
        {
            int PMTime = stoi(Hour) + 12;
            Hour = to_string(PMTime);
        }
    }
    return Hour + s.substr(2, 6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
