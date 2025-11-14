#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;

    deque<int> Deque;

    for (int i : numbers)
        Deque.push_back(i);

    if (direction == "right")
    {
        Deque.push_front(Deque.back());
        Deque.pop_back();
    }
    else if (direction == "left")
    {
        Deque.push_back(Deque.front());
        Deque.pop_front();
    }

    for (int i : Deque)
    {
        answer.push_back(i);
    }

    return answer;
}
