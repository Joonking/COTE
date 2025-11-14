#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int Alpabet[26] = { 0 };

	for (char c : s)
	{
		int index = c - 65; //A가 아스키코드 65
		if (c >= 97)  //97이 a임
		{
			index = index - 32;
		}

		Alpabet[index]++;
	}

	int MaxCount = 0;
	int MaxIndex = -1;
	int Overlap = 0;

	for (int i = 0; i < 26; i++)
	{
		if (Alpabet[i] > MaxCount)
		{
			MaxCount = Alpabet[i];
			MaxIndex = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (Alpabet[i] == MaxCount)
		{
			Overlap++;
		}
	}

	if (Overlap >= 2)
	{
		cout << "?";
	}
	else
	{
		char tempC = 65 + MaxIndex;
		cout << tempC << endl;
	}

	cout << "===========" << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << Alpabet[i] << " ";
	}

}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//
//    string s;
//    int a[26] = { 0 }, M = 0, t, B = 0;
//
//    cin >> s;
//
//    for (char c : s)
//    {
//        if (c > 96)
//            a[c - 97]++;
//        else
//            a[c - 65]++;
//    }
//
//    for (int i = 0; i < 26; i++)
//    {
//        if (a[i] > M)
//            M = a[i];
//    }
//
//    for (int i = 0; i < 26; i++)
//    {
//        if (a[i] == M)
//        {
//            t = i;
//            B++;
//        }
//    }
//
//    if (B > 1)
//        cout << "?";
//    else
//        cout << char(65 + t);
//}