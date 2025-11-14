//BFS 방식
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//
//int n, m;       //n : 유저 수, m : 친구 관계 수
//
//static vector<vector<int>> Friends;         //친구 배열
//static vector<bool> Visited;                    //방문 배열
//static vector<int> TempAnswer;              //임시 깊이 배열
//static vector<int> Answer;                      //유저 각자의 케빈 베이컨 수
//
//
//void BFS(int num)
//{
//    //first : 인덱스(유저번호), second : 깊이
//    queue<pair<int, int>> Queue;
//    Queue.push(make_pair(num, 0));    
//    Visited[num] = true;
//    TempAnswer[num] = 0;
//
//    while (Queue.empty() == false)
//    {
//        pair<int, int> OutNode = Queue.front();
//        Queue.pop();
//
//        for (int i = 0; i < Friends[OutNode.first].size(); i++)
//        {
//            int temp = Friends[OutNode.first][i];
//            if (Visited[temp] == false)
//            {
//                //cout << "OutNode : " << OutNode.first << ", temp : " << temp << endl;
//                Visited[temp] = true;
//                int depth = OutNode.second + 1;
//                Queue.push(make_pair(temp, depth));
//                TempAnswer[temp] = depth;
//            }
//        }
//    }
//
//    int sum = 0;
//    for (int i : TempAnswer)
//    {
//        sum += i;
//    }
//
//    Answer[num] = sum;
//    fill(TempAnswer.begin(), TempAnswer.end(), 0);
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> n >> m;
//
//    Friends.resize(n + 1);
//    Visited.resize(n + 1);
//    TempAnswer.resize(n + 1);
//    Answer.resize(n + 1);
//
//    for (int i = 0; i < m; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        Friends[a].push_back(b);
//        Friends[b].push_back(a);
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        BFS(i);
//        fill(Visited.begin(), Visited.end(), false);        //방문배열 초기화
//    }
//
//    int minPerson = 0;
//    int MIN = 100000;
//    for (int i = 1; i < Answer.size(); i++)
//    {
//        if (Answer[i] < MIN)
//        {
//            MIN = Answer[i];
//            minPerson = i;
//        }
//    }
//    cout << minPerson;
//  
//}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
long MDistance[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= N; k++)
		{
			if (i == k)
				MDistance[i][k] = 0;
			else
				MDistance[i][k] = 10000001;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int Start, End;
		cin >> Start >> End;
		MDistance[Start][End] = 1;
		MDistance[End][Start] = 1;
	}

	// 플로이드 워셜 알고리즘
	for (int t = 1; t <= N; t++) 
	{ 
		for (int i = 1; i <= N; i++) 
		{
			for (int k = 1; k <= N; k++) 
			{
				//i -> k 사이 관계에서 i -> t  + t -> k 관계로 가는게 더 작다면 업뎃
				if (MDistance[i][k] > MDistance[i][t] + MDistance[t][k])
					MDistance[i][k] = MDistance[i][t] + MDistance[t][k];
			}
		}
	}

	int Min = INT_MAX;
	int Answer = -1;

	for (int i = 1; i <= N; i++) 
	{
		int temp = 0;
		for (int k = 1; k <= N; k++)
		{
			temp += MDistance[i][k];  //i가 1일때 1행의 모든 열을 더하면 1번의 케빈베이컨의 수임.
		}
		//temp에는 각 행의 케빈베이컨 수가 담김. 이중에 제일 최소 값을 찾기
		if (Min > temp)  // 가장 작은 케빈 베이컨의 수를 지니고 있는 i를 찾기
		{
			Min = temp;
			Answer = i;
		}
	}
	cout << Answer;

	return 0;
}