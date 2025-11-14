#include<iostream>
using namespace std;

int main()
{
	int a, b, ab, r, GCD, LCM;

	cin >> a >> b;
	ab = a * b;
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	while (true)
	{
		r = a % b;
		if (r == 0)break;
		a = b;
		b = r;
	}
	
	GCD = b;
	LCM = ab / b;

	cout << GCD << endl;
	cout << LCM << endl;
}

/*

최대공약수 GCD(Greatest Common Divisor)
최소공배수 LCM(Least Common Multiple)

2개의 자연수를 받아 최대공약수를 받기 위해 2부터 두 자연수 중 작은 자연수까지
모두 나누어보면서 가장 큰 공약수를 구할 수 있음. (중학교때 배운 방법)
이렇게 풀면 시간복잡도는 O(N)임.
효율적으로 하려면 유클리드 호제법을 사용해야함. 시간복잡도는 O(logN).

유클리드 호제법 정의
2개의 자연수  a, b에 대해서 a를 b로 나눈 나머지를 r이라 하면(단 a > b), 
a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
이 성질에 따라, b를 r로 나눈 나머지 r0를 구하고, 
다시 r을 r0로 나눈 나머지를 구하는 과정을 반복하여 나머지가 0이 되었을 때 
나누는 수가 a와 b의 최대공약수이다.
이는 명시적으로 기술된 가장 오래된 알고리즘으로서도 알려져 있으며, 
기원전 300년경에 쓰인 유클리드의 <원론> 제7권, 명제 1부터 3까지에 해당한다.


ex> 72 와 30의 최대공약수와 최소공배수

		A			B			R (A%B)
		72			30			12
		30			12			6
		12			6			0				<--   나머지가 0이 되었을때 나누는 수 6(B)이 최대 공약수임.

		최소공배수는 두수 72와 30의 곱 에다가 최대 공약수를 나누면 알 수 있음.
		72 * 30 / 6 = 360
*/









