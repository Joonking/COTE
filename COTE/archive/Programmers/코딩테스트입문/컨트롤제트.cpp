#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string s) {
    int answer = 0;
    istringstream ss(s);
    string stringBuffer;
    vector<string> v;

    while (getline(ss, stringBuffer, ' ')) {
        v.push_back(stringBuffer);
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "Z")
            answer -= stoi(v[i - 1]);

        else
            answer += stoi(v[i]);
    }
    return answer;
}