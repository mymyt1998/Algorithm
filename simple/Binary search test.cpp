//找到最小自然数N，使N！在十进制下包含Q个0
//分治，二分
//判断N！的阶乘有多少0有公式，N/5+N/(5*5)+N/(5*5*5)
#include<iostream>
#include<cstdlib>
using namespace std;

int solve(int n)
{
	int ans = 0;
	while (n > 0)
	{
		ans = ans + n / 5;
		n /= 5;
	}
	return ans;
}
void run()
{
	int Q, i;
	cin >> Q;//0的数量
	int mid,t,start = 1;
	int end = 500000000;
	int ans = 500000001;
	while (start <= end)//二分查找
	{
		mid = (end - start) / 2 + start;//每次从1到500000000中间找
		t = solve(mid);//mid阶乘0的数量
		if (t == Q && mid < ans)
			ans = mid;
		if (t > Q)
			end = mid - 1;
		else if (t < Q)
			start = mid + 1;
		else
			end = mid - 1;
	}
	if (ans != 500000001)
		cout << ans << endl;
	else
		cout << "No solution" << endl;
}

int main()
{
	run(); 
	return 0;
}