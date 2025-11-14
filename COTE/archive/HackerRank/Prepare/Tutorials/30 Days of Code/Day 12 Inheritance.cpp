#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class student
{
public:
    student(string fN, string lN, string id) {
        firstName = fN;
        lastName = lN;
        idNumber = id;
    };

    void PrintName() {
        cout << "Name: " << lastName << ", " << firstName << "\n";
    }

    void PrintID() {
        cout << "ID: " << idNumber << "\n";
    }

    void PrintGrade() {
        if (AverageScore >= 90)
            cout << "Grade: O" << "\n";
        else if (AverageScore >= 80)
            cout << "Grade: E" << "\n";
        else if (AverageScore >= 70)
            cout << "Grade: A" << "\n";
        else if (AverageScore >= 55)
            cout << "Grade: P" << "\n";
        else if (AverageScore >= 40)
            cout << "Grade: D" << "\n";
        else
            cout << "Grade: T" << "\n";
    }

    void SetGrade(const vector<int>& ScoreList)
    {
        float Size = ScoreList.size();
        float Sum = 0;
        for (int i : ScoreList)
        {
            Sum += i;
        }
        AverageScore = Sum / Size;
    }

private:
    string firstName;
    string lastName;
    string idNumber;
    float AverageScore = 0;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */


    string TempStr1, TempStr2, TempStr3;
    cin >> TempStr1 >> TempStr2 >> TempStr3;

    int ScoreNum = 0;
    cin >> ScoreNum;
    vector<int> ScoreList(ScoreNum);

    for (int i = 0; i < ScoreNum; i++)
    {
        cin >> ScoreList[i];
    }

    student* S = new student(TempStr1, TempStr2, TempStr3);
    S->SetGrade(ScoreList);

    S->PrintName();
    S->PrintID();
    S->PrintGrade();

    return 0;
}
