#include <iostream>
using namespace std;

int main()
{
    int N, A, sum = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if (A == 2)
        {
            sum++;
            continue;
        }

        for (int j = 2; j < A; j++)
        {
            if (A % j == 0)
                break;
            if (j == A - 1)
                sum++;
        }
    }

    cout << sum;
}