#include <iostream>
#include <algorithm>

using namespace std;

unsigned int K, N;
unsigned int ans;
unsigned int list[10000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;

    unsigned int MAX = 0;
    for(int i=0;i<K;i++)
    {
        cin >> list[i];
        MAX = max(MAX, list[i]);
    }
    unsigned int left = 1;
    unsigned int right = MAX;
    unsigned int mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        unsigned int count = 0;

        for (int i = 0; i < K; i++)
            count += list[i] / mid;


        if(count >=N)
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans << endl;
}