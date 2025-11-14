#include <iostream>

using namespace std;

int main() {
    int goo[9][9], bi, bj, max = -1;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> goo[i][j];
            if (goo[i][j] > max)
            {
                max = goo[i][j];
                bi = i+1;
                bj = j+1;
            }
        }
    }

    cout << max << endl;
    cout << bi << " " << bj << endl;
    
}



