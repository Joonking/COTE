#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A, B, res, ans;
    cin >> A >> B;
    int car = 0;
    int onesize = A.size();
    int twosize = B.size();
    while (onesize > 0 || twosize > 0)
    {
        int nA = 0;
        if (onesize > 0)
        {
            nA = A[--onesize] - '0';
        }
        int nB = 0;
        if (twosize > 0)
        {
            nB = B[--twosize] - '0';
        }
        int cur = nA + nB + car;
        car = cur / 10;
        cur %= 10;
        char ccar = cur + '0';
        res += ccar;
    }
    if (car > 0)
    {
        res += car + '0';
    }
    for (int i = res.length() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}




