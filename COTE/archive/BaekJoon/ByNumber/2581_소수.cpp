#include <iostream>
using namespace std;

int main()
{
    int M, N, min=10000, sum=0;
    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        if (i == 2)
        {
            sum += 2;
            min = 2;
            continue;
        }

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
            
            if (j == i - 1)
            {
                if (j < min)
                    min = j+1;

                sum += j+1;
            }
        }
    }

    if (sum == 0)
    {
        cout << -1;
        return 0;
    }
    cout << sum << endl;
    cout << min;

}