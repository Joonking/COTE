#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a == 0) break;

		vector<int> tri;
		tri.push_back(a);
		tri.push_back(b);
		tri.push_back(c);
		sort(tri.begin(), tri.end());

		if (tri[2] >= tri[1] + tri[0])
			cout << "Invalid" << "\n";
		else if (tri[0] == tri[1] && tri[1] == tri[2] && tri[0] == tri[2])
			cout << "Equilateral" << "\n";
		else if (tri[0] == tri[1] || tri[0] == tri[2] || tri[1] == tri[2])
			cout << "Isosceles" << "\n";
		else if (tri[0] != tri[1] != tri[2])
			cout << "Scalene" << "\n";

	}

}


