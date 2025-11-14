#include <iostream>

int main()
{
	int n, k=1;
	std::cin >> n;
	if (n == 1)
	{
		std::cout << 1;
		return 0;
	}
	
	while (3*k*k -3*k +1 < n)
			k++;
	std::cout << k;
}