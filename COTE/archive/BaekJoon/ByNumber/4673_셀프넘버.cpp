#include <iostream>

int d(int n)
{
	int sum = n;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

bool IsSelfNum(int n)
{
	for (int i = 1; i < n; i++)
	{
		if (d(i) == n)
			return false;
	}
	return true;
}

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (IsSelfNum(i))
			std::cout << i << std::endl;
	}
}






