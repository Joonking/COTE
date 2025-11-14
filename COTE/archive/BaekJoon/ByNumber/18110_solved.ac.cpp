#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    float res = 0;
    cin >> n;

    if (n == 0) //n이 0이면 0출력 후 종료
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];    //입력

    float tmp = n * 0.15;    // 30%의 절사평균을 구함
    // 아래, 위로 15%

    tmp = round(tmp);    //반올림
    sort(v.begin(), v.end());    //정렬

    for (int i = tmp; i < n - tmp; i++) {    //반올림한 절사평균을
        res += v[i];                        // 아래15%, 위 15%명을 제외하고 더함
    }
    res /= (n - tmp * 2);    //평균
    res = round(res);    //반올림

    cout << res << endl;
    return 0;

}