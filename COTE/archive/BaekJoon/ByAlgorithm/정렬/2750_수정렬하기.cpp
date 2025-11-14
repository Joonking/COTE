
//버블정렬 ----------------------------------------------------
#include <iostream>
using namespace std;

int main() {

	int n, a[1000], t;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}

//삽입정렬--------------------------------------------------------------

/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, t;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] <= v[i])
			continue;

		int temp = v[i];

		for (int k = 0; k < i; k++)
		{
			if (v[k] > temp)
			{
				v.erase(v.begin() + i);   //i번째 요소 삭제
				v.insert(v.begin() + k, temp);  //k번째에 temp 값 삽입
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << v[i] << endl;

}
*/


//sort 사용----------------------------------------------------------------------
/*
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, v[1000];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v, v + n);

	for (int i = 0; i < n; i++)
		cout << v[i] << endl;

}
*/