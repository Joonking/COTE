#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);



/*
 * Complete the 'truckTour' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
 */

int truckTour(vector<vector<int>> petrolpumps) {
    int totalPetrol = 0;  // 전체 주유소에서 얻은 총 연료
    int totalDistance = 0;  // 전체 주유소 사이의 총 거리
    int start = 0;  // 트럭이 출발할 수 있는 첫 번째 주유소의 인덱스
    int surplus = 0;  // 트럭이 출발 이후 남은 연료

    for (int i = 0; i < petrolpumps.size(); i++) {
        totalPetrol += petrolpumps[i][0];  // i번 주유소에서 주유한 양
        totalDistance += petrolpumps[i][1];  // i번 주유소에서 다음 주유소까지의 거리
        surplus += petrolpumps[i][0] - petrolpumps[i][1];  // 해당 주유소에서 남는 연료 계산

        // 남는 연료가 음수인 경우 출발할 수 없으므로, 다음 주유소에서 다시 시작
        if (surplus < 0) {
            start = i + 1;  // 다음 주유소를 출발점으로 설정
            surplus = 0;  // 남은 연료를 다시 0으로 초기화
        }
    }

    return start;  // 첫 번째로 출발할 수 있는 주유소의 인덱스 반환
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> petrolpumps(n);

    for (int i = 0; i < n; i++) {
        petrolpumps[i].resize(2);

        string petrolpumps_row_temp_temp;
        getline(cin, petrolpumps_row_temp_temp);

        vector<string> petrolpumps_row_temp = split(rtrim(petrolpumps_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int petrolpumps_row_item = stoi(petrolpumps_row_temp[j]);

            petrolpumps[i][j] = petrolpumps_row_item;
        }
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

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

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}