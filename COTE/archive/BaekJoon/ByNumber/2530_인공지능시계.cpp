#include <iostream>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int hh, mm, ss, Time;
	cin >> hh >> mm >> ss >> Time;

	int NewTime = hh * 3600 + mm * 60 + ss + Time;

	//하루는 86400초
	NewTime %= 86400;

	int Newhh = NewTime / 3600;
	int Newmm = (NewTime % 3600) / 60;
	int Newss = NewTime % 60;

	cout << Newhh << " " << Newmm << " " << Newss << '\n';

	return 0;
}