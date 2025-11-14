#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int T, sum, sub, result;
	int x1, y1, r1, x2, y2, r2;
	cin >> T;
	double distance;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//distance^2=(x2-x1)^2+(y2-y1)^2
		distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		sum = r1 + r2;
		sub = abs(r1 - r2); //절댓값
		if (distance == 0 && r1 == r2) result = -1; //교점 무한.
		else if (distance == sum || distance == sub) result = 1;//교점 1개
		else if (sub < distance && distance < sum) result = 2;//교점 2개.	
		else result = 0;//만나지 않는 경우	
		cout << result << "\n";
	}
	return 0;
}