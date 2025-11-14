#include <iostream>
#include <stack>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    string S = "";
    stack<pair<int, string>> StackEditor;

    for (int i = 0; i < Q; i++)
    {
        int Type;
        cin >> Type;

        switch (Type)
        {
        case 1:
        {
            string StrTemp;
            cin >> StrTemp;
            StackEditor.push({ 1, StrTemp });
            S += StrTemp;
            break;
        }
        case 2:
        {
            int k;
            cin >> k;
            string SubString = S.substr(S.size() - k, k);
            StackEditor.push({ 2, SubString });
            S = S.substr(0, S.size() - k);
            break;
        }
        case 3:
        {
            int k;
            cin >> k;
            cout << S[k - 1] << "\n";
            break;
        }
        case 4:
        {
            if (StackEditor.empty())
                break;

            if (StackEditor.top().first == 1)
            {
                string SubString = StackEditor.top().second;
                StackEditor.pop();
                S = S.substr(0, S.size() - SubString.size());
            }
            else if (StackEditor.top().first == 2)
            {
                S += StackEditor.top().second;
                StackEditor.pop();
            }

            break;
        }
        default:
        {

            break;
        }
        }
    }

    return 0;
}
