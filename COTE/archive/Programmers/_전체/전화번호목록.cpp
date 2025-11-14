#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> hash;

    for (auto i : phone_book)
    {
        hash[i]++;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            phone_number += phone_book[i][j];
            //해쉬에 있는 번호랑 phone_number가 같으면서, 
            //phone_number가 현재 검사하는 phone_book의 번호가 아닐때
            if (hash[phone_number] && phone_number != phone_book[i])
                return false;
        }
    }
    return true;
}