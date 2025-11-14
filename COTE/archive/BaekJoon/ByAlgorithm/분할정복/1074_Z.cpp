#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;    //n : 2의n승 배열 크기, r : 찾으려는 값 행, c : 찾으려는 값 열
int ans;        //ans : 탐색 횟수

void Z(int y, int x, int size)
{
    if (y == r && x == c)    //y, x가 찾으려는 행, 열이랑 같으면
    {
        cout << ans << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (y<= r && r < y + size && x <=c && c < x + size)
    {
        // 1사분면 탐색
        Z(y, x, size / 2);
        // 2사분면 탐색
        Z(y, x + size / 2, size / 2);
        // 3사분면 탐색
        Z(y + size / 2, x, size / 2);
        // 4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else  //r,c가 현재 사분면에 없다면
    {
        ans += size * size;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    Z(0, 0, pow(2, n));
    return 0;
}