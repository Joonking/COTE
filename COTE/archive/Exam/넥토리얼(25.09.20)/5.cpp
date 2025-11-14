#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<int> closest(string s, vector<int> queries) {
    vector<int> result;

    for (int query : queries) {
        int minDist = INT_MAX;
        int closestIndex = -1;

        // 숫자 문자(0-9)만 고려
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                int digit = s[i] - '0';
                int dist = abs(digit - query);
                if (dist < minDist) {
                    minDist = dist;
                    closestIndex = i;
                }
            }
        }

        result.push_back(closestIndex);
    }

    return result;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = closest(s, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}