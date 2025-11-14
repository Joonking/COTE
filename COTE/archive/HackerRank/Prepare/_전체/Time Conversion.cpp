#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int size = s.size();

    char AMPM = s[size - 2];
    string FrontTwoCharacter = s.substr(0, 2);
    int FrontTwoInt = stoi(FrontTwoCharacter);
    if (AMPM == 'A')
    {
        if (FrontTwoInt == 12)
        {
            FrontTwoCharacter = "00";
        }
    }
    else if (AMPM == 'P')
    {
        if (FrontTwoInt < 12)
        {
            FrontTwoInt += 12;
            FrontTwoCharacter = to_string(FrontTwoInt);
        }
    }
    s = s.substr(2, 6);
    string result = FrontTwoCharacter + s;
    return result;
}

//GPT 코드 이게 훨씬 나음
//string timeConversion(string s) {
//    string hour = s.substr(0, 2);
//    string period = s.substr(8, 2);
//
//    if (period == "AM") {
//        if (hour == "12") hour = "00";
//    }
//    else {
//        if (hour != "12") hour = to_string(stoi(hour) + 12);
//    }
//
//    return hour + s.substr(2, 6);
//}

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
