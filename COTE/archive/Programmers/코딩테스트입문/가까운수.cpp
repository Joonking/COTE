#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int min = 1000;
    sort(array.begin(), array.end());
    for (int i : array)
    {
        int temp = n - i;
        if (abs(temp) < min)
        {
            min = abs(temp);
            answer = i;
        }
    }

    return answer;
}