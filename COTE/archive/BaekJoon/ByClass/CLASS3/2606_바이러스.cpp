#include <iostream>
#include <vector>
using namespace std;

static vector<int> Parent;

int Find(int a)
{
	if (Parent[a] == a)
		return a;
	else
		return Parent[a] = Find(Parent[a]);
}

void Uni(int n1, int n2)
{
	n1 = Find(n1);
	n2 = Find(n2);

	if (n1 != n2)
	{
		Parent[n2] = n1;
	}
		
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;   //N : 컴퓨터 수, M : 연결 선의 수
	cin >> N >> M;

	Parent.resize(N + 1);
	for(int i =0; i<=N;i++)
	{
		Parent[i] = i;
	}

	for(int i=0;i<M;i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		Uni(n1, n2);
	}

	int answer = 0;

	for(int i=2;i<=N;i++)
	{
		if (Find(1) == Find(i))
			answer++;
	}

	cout << answer<< endl;

}