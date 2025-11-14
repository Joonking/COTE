#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N;
    cin >> N;

    unordered_map<string, string> Umap;

    for (int i = 0; i < N; i++)
    {
        string Name, PhoneNum;
        cin >> Name >> PhoneNum;
        Umap[Name] = PhoneNum;
    }

    string FindName;

    while (cin >> FindName) {
        if (Umap.find(FindName) != Umap.end()) {
            cout << FindName << "=" << Umap[FindName] << "\n";
        }
        else {
            cout << "Not found" << "\n";
        }
    }


    return 0;
}
