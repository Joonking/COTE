#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	//set은 기본적으로 오름차순 정렬 
	set<string> NoHear;
	set<string> NoHearNoSee;

	//내림차순으로 하고싶다면
	//set<string, greater<string>> NoHear;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		NoHear.insert(temp);
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (NoHear.find(temp) != NoHear.end())
			NoHearNoSee.insert(temp);
	}

	cout << NoHearNoSee.size() << "\n";
	for (string a : NoHearNoSee)
	{
		cout << a << "\n";
	}

	return 0;
}

//이전 코드
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N, M;
//
//	cin >> N >> M;
//	unordered_map<string, int> hash;
//	vector<string> answer;
//	for(int i=0;i<N;i++)
//	{
//		string temp;
//		cin >> temp;
//		hash[temp]++;
//	}
//
//	for (int i = 0; i < M; i++)
//	{
//		string temp;
//		cin >> temp;
//		hash[temp]++;
//	}
//	
//	for(auto a : hash)
//	{
//		if (a.second == 2)
//			answer.push_back(a.first);
//	}
//
//	sort(answer.begin(), answer.end());
//	cout << answer.size() << endl;
//	for(auto a : answer)
//	{
//		cout << a << endl;
//	}
//}