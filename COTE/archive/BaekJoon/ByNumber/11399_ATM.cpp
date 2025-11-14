#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	//인출에 걸리는 시간 배열
	vector<int> Pi(N);
	//합 배열
	vector<int> S(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Pi[i];
	}

	//삽입정렬
	for (int i = 1; i < N; i++)
	{
		int InsertPoint = i;
		int InsertValue = Pi[i];

		for (int k = i - 1; k >= 0; k--)
		{
			//삽입할 애(Pi[i])가 더 큰 상황을 찾아서
			//그 뒤로 삽입
			if (Pi[k] < Pi[i])
			{
				InsertPoint = k + 1;
				break;
			}
			//k가 0까지 왔으면 삽입할 애는 맨 앞으로 삽입가능
			if (k == 0)
			{
				InsertPoint = 0;
			}
		}

		//삽입할애 자리 마련하주기
		// 삽입할 애 자리 i 부터 삽입 인덱스 전까지만
		for (int k = i; k > InsertPoint; k--)
		{
			//앞에 있는걸 넣어주기
			Pi[k] = Pi[k - 1];
		}
		//삽입 포인트에 삽입할 값 백업했던거 넣어주기.
		Pi[InsertPoint] = InsertValue;
	}

	//합배열 만들기
	S[0] = Pi[0];
	for (int i = 1; i < N; i++)
	{
		S[i] = S[i - 1] + Pi[i];
	}

	int Sum = 0;
	for (int i : S)
	{
		Sum += i;
	}

	cout << Sum;

	return 0;
}