/*
核桃的数量
1. 各组的核桃数量必须相同
2. 各组内必须能平分核桃（当然是不能打碎的）
3. 尽量提供满足1,2条件的最小数量（节约闹革命嘛）
*/
//找3个数的最小公倍数
#include<iostream>
using namespace std;
int num(int x, int y)//求最小公因子
{
	//更相减损法
	while (x!=y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}
int main()
{
	int ans,a, b, c, i,x;
	while (cin >> a >> b >> c)//加班人数
	{
		x = num(a, b);//2
		x = a*b / x;//4
		ans = num(x, c);//4 5
		ans = x*c / ans;
		cout << ans << endl;
	}
	return 0;
}
