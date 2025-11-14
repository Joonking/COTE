#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//A, B, C의 부피 (인덱스 0 : A, 1 : B, 2 : C)
int Volume[3] = { 0 };

//정답 담을 bool 배열, 체크된 곳의 인덱스값이 곧 A가 0일때 C의 남은 물 양
bool Ans[201] = { false };
//A, B의 값이 나왔던건지 체크하기 위한 방문배열. 
bool Visited[201][201] = { false };

//A,B,C의 이동을 표현
// [0, 1] : 보내는쪽 A(0) -> 받는쪽 B(1)
// [0, 2] : 보내는쪽 A(0) -> 받는쪽 C(2)
// [1, 0] : 보내는쪽 B(1) -> 받는쪽 A(0)
// [1, 2] : 보내는쪽 B(1) -> 받는쪽 C(2)
// [2, 0] : 보내는쪽 C(2) -> 받는쪽 A(0)
// [2, 1] : 보내는쪽 C(2) -> 받는쪽 B(1)
int Sender[] = { 0, 0, 1, 1, 2, 2 };   //보내는 쪽
int Receiver[] = { 1, 2, 0, 2, 0, 1 }; //받는 쪽

void BFS()
{
	queue<pair<int, int>> Queue;
	Queue.push({ 0, 0 });
	Visited[0][0] = true;
	Ans[Volume[2]] = true;

	while (Queue.empty() == false)
	{
		pair<int, int> Front = Queue.front();
		Queue.pop();

		int NowA = Front.first;
		int NowB = Front.second;
		int NowC = Volume[2] - NowA - NowB;

		for (int i = 0; i < 6; i++)
		{
			//물을 배분하고 난 뒤의 배열 0, 1, 2 순으로 A, B, C
			int Next[] = { NowA, NowB, NowC };

			//물을 받는곳의 양에 물을 보내는 곳의 양을 더해줌.
			Next[Receiver[i]] += Next[Sender[i]];
			//물을 보낸 곳은 0으로 (물통은 한번에 다 줄 수밖에 없음)
			Next[Sender[i]] = 0;

			//받는 쪽에서 부피보다 양이 더 많이 왔을 경우 재분배
			if (Next[Receiver[i]] > Volume[Receiver[i]])
			{
				//보낸 쪽에다가 (받는쪽의 넘치는 양 - 받는쪽의 부피)를 보내줌
				Next[Sender[i]] = Next[Receiver[i]] - Volume[Receiver[i]];
				//보낸 쪽은 가득 찬거니까 부피 값으로
				Next[Receiver[i]] = Volume[Receiver[i]];
			}

			//A, B 값이 나온곳이 아닌 곳만 (방문하지 않은 곳만)
			if (Visited[Next[0]][Next[1]] == false)
			{
				//일단 방문 처리
				Visited[Next[0]][Next[1]] = true;
				//A, B의 값을 Push
				Queue.push({ Next[0], Next[1] });

				//A값이 0이 될때의 C 값을 정답에 추가
				if (Next[0] == 0)
				{
					Ans[Next[2]] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//A, B, C의 부피 값 받기
	cin >> Volume[0] >> Volume[1] >> Volume[2];
	BFS();

	//정답 배열 돌면서 true인 곳의 index 출력
	for (int i = 0; i < 201; i++)
	{
		if (Ans[i])
			cout << i << " ";
	}

	return 0;
}