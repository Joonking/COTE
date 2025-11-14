//067_11725 트리의 부모 찾기

#include <iostream>
#include <vector>

using namespace std;

static int N;
static vector<vector<int>> tree;
static vector<bool> visited;
static vector<int> answer;
void DFS(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tree.resize(N + 1);
	visited.resize(N + 1);
	answer.resize(N + 1);

	for(int i=1;i<N;i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	DFS(1);

	for(int i=2;i<=N;i++)
	{
		cout << answer[i] << "\n";
	}
}

void DFS(int num)
{
	visited[num] = true;

	for(int i : tree[num])
	{
		if(!visited[i])
		{
			answer[i] = num;
			DFS(i);
		}
	}

}