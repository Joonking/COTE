#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, string>> IntStringVector;

	for (int i = 0; i < N; i++)
	{
		string TempStr;
		cin >> TempStr;
		IntStringVector.push_back({ TempStr.size(), TempStr });
	}

	sort(IntStringVector.begin(), IntStringVector.end(), [](pair<int, string>& a, pair<int, string>& b) {
		if (a.first == b.first)   //길이가 같으면
			return a.second < b.second;   //사전순으로 오름차순
		return a.first < b.first;  //길이가 다르면 길이 짧은 순으로 오름차순
		});

	//출력 : 중복된 문자열은 무시
	string PrevString = "";   //이전 문자열 저장
	for (int i = 0; i < N; i++)
	{
		//이전 문자와 문자가 같으면 넘어가
		if (IntStringVector[i].second == PrevString)
			continue;

		PrevString = IntStringVector[i].second;
		cout << IntStringVector[i].second << endl;
	}

	return 0;
}

//이전 코드
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	vector<pair<int, string>> v;
//
//	string strTemp;
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> strTemp;
//		v.push_back({ strTemp.size(), strTemp });
//	}
//	sort(v.begin(), v.end());
//
//	for (int i = 1; i < n; i++)
//	{
//		if (v[i - 1].second == v[i].second)
//			v[i].first = 100;
//	}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i].first == 100)
//			continue;
//		cout << v[i].second << '\n';
//	}
//}