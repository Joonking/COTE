#include <iostream>

using namespace std;

int main() {
    
    int n, Do[100][100]={0}, x, y, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (int j = x; j < x + 10; j++)
        {
            for (int k = y; k < y + 10; k++)
            {
                if (j >= 100 || k >= 100)
                    break;

                if (Do[j][k] == 0)
                {
                    Do[j][k] = 1;
                    sum++;
                }
            }
        }
    }

    cout << sum;
}
