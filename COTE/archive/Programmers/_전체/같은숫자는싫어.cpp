#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            answer.push_back(arr[i]);
        else
        {
            if (arr[i - 1] != arr[i])
                answer.push_back(arr[i]);
        }
    }

    return answer;
}


//----------------------------------------------------------------
//다른사람 풀이

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> answer = arr;
    return answer;
}