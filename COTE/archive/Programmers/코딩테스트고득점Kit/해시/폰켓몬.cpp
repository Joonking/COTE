#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size() / 2;

    unordered_map<int, int> map;     //키 : 폰켓몬 종류, 값 : 폰켓몬 개수

    for (int i : nums)
    {
        map[i]++;
    }

    int size = map.size();

    if (size > N)
        answer = N;
    else
        answer = size;

    return answer;
}