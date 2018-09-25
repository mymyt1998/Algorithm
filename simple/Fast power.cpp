//快速幂运算x^n
#include<iostream>
using namespace std;
/*
int pow(int x, int y)
{
	if (y == 1)
		return x;
	int c = pow(x, y / 2);
	if (!(y % 2))
		return c*c;
	return c*c*x;
}
int main()
{
	int x, n;
	while(cin >> x >> n)
	cout << pow(x, n) << endl;
	return 0;
}
*/
long long Pow(long long x, long long n)//位运算优化
{
	long long result;
	if (!n)
		return 1;
	while (!(n & 1))//当N为偶数时
	{
		n >>= 1;//即n=n/2;
		x *= x;
	}
	result = x;
	n >>= 1;
	while (n)
	{
		x *= x;
		if (n & 1)//n为奇数时
			result *= x;
		n >>= 1;
	}
	return result;
}
int main()
{
	long long x, n;
	while (cin >> x >> n)
		cout << Pow(x, n) << endl;
	return 0;
}