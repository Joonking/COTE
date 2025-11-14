#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;

    int index = 0;
    for (int i = 1; i < k; i++)
    {
        index += 2;
        if (index >= numbers.size())
            index -= numbers.size();
    }
    answer = numbers[index];

    return answer;
}
