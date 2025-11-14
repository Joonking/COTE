#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

int getBingoNumber(vector<vector<int>>& mat, vector<int>& arr) {
    int rows = mat.size();
    int cols = mat[0].size();

    // 숫자의 위치를 미리 저장
    unordered_map<int, pair<int, int>> positions;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            positions[mat[i][j]] = {i, j};
        }
    }

    vector<vector<bool>> marked(rows, vector<bool>(cols, false));
    vector<int> row_count(rows, 0);  // 각 행의 마킹된 개수
    vector<int> col_count(cols, 0);  // 각 열의 마킹된 개수

    for (int num : arr) {
        // 해시맵을 사용해 O(1)로 위치 찾기
        if (positions.find(num) != positions.end()) {
            int row = positions[num].first;
            int col = positions[num].second;

            if (!marked[row][col]) {
                marked[row][col] = true;
                row_count[row]++;
                col_count[col]++;

                // 빙고 체크 - 해당 행/열만 체크
                if (row_count[row] == cols || col_count[col] == rows) {
                    return num;
                }
            }
        }
    }

    return -1; // 빙고가 없는 경우
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int mat_rows, mat_columns;
    input >> mat_rows >> mat_columns;

    vector<vector<int>> mat(mat_rows, vector<int>(mat_columns));
    for (int i = 0; i < mat_rows; i++) {
        for (int j = 0; j < mat_columns; j++) {
            input >> mat[i][j];
        }
    }

    int arr_count;
    input >> arr_count;

    vector<int> arr(arr_count);
    for (int i = 0; i < arr_count; i++) {
        input >> arr[i];
    }

    int result = getBingoNumber(mat, arr);
    output << result << endl;

    input.close();
    output.close();

    return 0;
}

//
// #include <iostream>
// #include <vector>
// #include <fstream>
//
// using namespace std;
//
// int getBingoNumber(vector<vector<int>>& mat, vector<int>& arr) {
//     int n = mat.size();
//     vector<vector<bool>> marked(n, vector<bool>(n, false));
//
//     for (int num : arr) {
//         // 현재 숫자를 매트릭스에서 찾아서 마킹
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] == num) {
//                     marked[i][j] = true;
//                     break;
//                 }
//             }
//         }
//
//         // 빙고 체크
//         // 가로 체크
//         for (int i = 0; i < n; i++) {
//             bool bingo = true;
//             for (int j = 0; j < n; j++) {
//                 if (!marked[i][j]) {
//                     bingo = false;
//                     break;
//                 }
//             }
//             if (bingo) return num;
//         }
//
//         // 세로 체크
//         for (int j = 0; j < n; j++) {
//             bool bingo = true;
//             for (int i = 0; i < n; i++) {
//                 if (!marked[i][j]) {
//                     bingo = false;
//                     break;
//                 }
//             }
//             if (bingo) return num;
//         }
//
//         // 대각선 체크 (왼쪽 위 -> 오른쪽 아래)
//         bool bingo1 = true;
//         for (int i = 0; i < n; i++) {
//             if (!marked[i][i]) {
//                 bingo1 = false;
//                 break;
//             }
//         }
//         if (bingo1) return num;
//
//         // 대각선 체크 (오른쪽 위 -> 왼쪽 아래)
//         bool bingo2 = true;
//         for (int i = 0; i < n; i++) {
//             if (!marked[i][n-1-i]) {
//                 bingo2 = false;
//                 break;
//             }
//         }
//         if (bingo2) return num;
//     }
//
//     return -1; // 빙고가 없는 경우
// }
//
// int main() {
//     ifstream input("input.txt");
//     ofstream output("output.txt");
//
//     int mat_rows, mat_columns;
//     input >> mat_rows >> mat_columns;
//
//     vector<vector<int>> mat(mat_rows, vector<int>(mat_columns));
//     for (int i = 0; i < mat_rows; i++) {
//         for (int j = 0; j < mat_columns; j++) {
//             input >> mat[i][j];
//         }
//     }
//
//     int arr_count;
//     input >> arr_count;
//
//     vector<int> arr(arr_count);
//     for (int i = 0; i < arr_count; i++) {
//         input >> arr[i];
//     }
//
//     int result = getBingoNumber(mat, arr);
//     output << result << endl;
//
//     input.close();
//     output.close();
//
//     return 0;
// }