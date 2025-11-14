#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int arr[3];
    int sum = 0;

    cin >> arr[0] >> arr[1] >> arr[2];
    for (int a : arr)
        sum += a;

    cout << sum;

    return 0;
}
