#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, T=2;
    vector<int> V;
    cin >> N;

    while (N>1)
    {
        if (N % T == 0)
        {
            N /= T;
            V.push_back(T);
            continue;
        }
        T++;
    }

    for (int i : V)
        cout << i << endl;

}



