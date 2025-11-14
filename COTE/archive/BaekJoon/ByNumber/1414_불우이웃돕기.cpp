#include <iostream>
#include <queue>
using namespace std;

struct Edge
{
	int Start, End, Cost;
	Edge(int S, int E, int C) : Start(S), End(E), Cost(C) {}
	bool operator>(const Edge& temp) const
	{
		return Cost > temp.Cost;
	}
};

vector<int> Parent;

int FindFunction(int Num)
{
	if (Parent[Num] == Num)
		return Num;
	return Parent[Num] = FindFunction(Parent[Num]);
}

void UnionFunction(int A, int B)
{
	A = FindFunction(A);
	B = FindFunction(B);
	if (A != B)
		Parent[B] = A;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int Sum = 0;

	priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			char TempChar = cin.get();
			if (TempChar == '\n')
				TempChar = cin.get();

			int Temp = 0;
			if (TempChar >= 'a' && TempChar <= 'z')
			{
				Temp += TempChar - 'a' + 1;
			}
			else if (TempChar >= 'A' && TempChar <= 'Z')
			{
				Temp += TempChar - 'A' + 27;
			}
			//총 랜선 길이 저장
			Sum += Temp;

			//자기자신으로의 랜선이 아니고 길이가 0이 아니면 엣지 저장.
			if (i != k && Temp != 0)
			{
				PQ.push(Edge(i, k, Temp));
			}
		}
	}

	Parent.resize(N);
	for (int i = 0; i < N; i++)
		Parent[i] = i;

	int UseEdge = 0;
	int Result = 0;
	while (PQ.empty() == false)
	{
		Edge Now = PQ.top();
		PQ.pop();

		if (FindFunction(Now.Start) != FindFunction(Now.End))                                                                                                                                                                                                                                                                                                                                                                           
		{
			UnionFunction(Now.Start, Now.End);
			Result += Now.Cost;
			UseEdge++;
		}
	}

	//크루스칼 알고리즘이 끝났을 때 사용한 엣지 수가
	//N-1이라는 소리는 총 N개니까 모두 연결이 된거임.
	//N-1 보다 작다는 소리는 다 연결이 안된거고
	//N-1보다 커질 수는 없음.
	if (UseEdge == N - 1)
		cout << Sum - Result << "\n";
	else
		cout << -1 << "\n";

	return 0;
}