#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int q;
    cin >> q;
    stack<int> Stack1;
    stack<int> Stack2;

    for (int i = 0; i < q; i++)
    {
        int Type;
        cin >> Type;

        if (Type == 1)
        {
            int Value;
            cin >> Value;
            Stack1.push(Value);
        }
        else if (Type == 2)
        {
            if (Stack2.empty())
            {
                while (Stack1.empty() == false)
                {
                    Stack2.push(Stack1.top());
                    Stack1.pop();
                }
            }
            Stack2.pop();
        }
        else if (Type == 3)
        {
            if (Stack2.empty())
            {
                while (Stack1.empty() == false)
                {
                    Stack2.push(Stack1.top());
                    Stack1.pop();
                }
            }
            cout << Stack2.top() << "\n";
        }
    }

    return 0;
}