//대현이형 코드

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Account
{
    int ID;
    int Age;
    string Name;
};

bool operator>(Account const& Left, Account const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID > Right.ID;
    return Left.Age > Right.Age;
}
bool operator<(Account const& Left, Account const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID < Right.ID;
    return Left.Age < Right.Age;
}

vector<Account> Arr{};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        Account elem{};
        elem.ID = i;
        cin >> elem.Age >> elem.Name;
        Arr.push_back(elem);
    }
    sort(Arr.begin(), Arr.end());

    for (auto const& elem : Arr)
    {
        cout << elem.Age << " " << elem.Name << "\n";
    }

    return 0;
}


//==================================================


//내코드 
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int ID;
    int Age;
    string Name;
};

bool operator>(node const& Left, node const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID > Right.ID;
    return Left.Age > Right.Age;
}

bool operator<(node const& Left, node const& Right)
{
    if (Left.Age == Right.Age)
        return Left.ID < Right.ID;
    return Left.Age < Right.Age;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<node> arr;

    for (int i = 0; i < n; i++)
    {
        node tempNode;
        tempNode.ID = i;
        cin >> tempNode.Age >> tempNode.Name;
        arr.push_back(tempNode);
    }

    sort(arr.begin(), arr.end());

    for (node a : arr)
    {
        cout << a.Age << " " << a.Name << '\n';
    }

    return 0;
}

*/
