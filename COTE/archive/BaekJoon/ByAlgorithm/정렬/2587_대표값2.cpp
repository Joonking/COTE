//삽입정렬 사용
#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int t, sum =0;
	vector<int> v;

	for (int i = 0; i < 5; i++)
	{
		cin >> t;
		v.push_back(t);
		sum += t;
	}

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] < v[i])
			continue;

		for (int k = 0; k < i; k++) {
			if (v[k] > v[i])
			{
				int temp = v[i];
				v.erase(v.begin() + i);
				v.insert(v.begin() + k, temp);
				break;
			}
		}
	}

	cout << sum / 5 << endl;
	cout << v[2];

}



