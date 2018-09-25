//分数有理化
#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
bool f1=false,f2=false;//记录是否有负号
int init()//初始化输入数据
{
	int x = 0;
	char c;
	while (1)
	{
		c = getchar();
		if (c == '-')
		{
			f1 = true;
			continue;
		}
		if (c == '/' || c == ' ' || c == '\n')
			return x;
		x *= 10;
		x += int(c - '0');
	}	
}
int prime(int x, int y)
{
	while (x != y)
	{
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}
	return x;
}
string pt(int x, int y)//转化为有理数格式 5 3
{
	if (y == 0)//分母为0
		return "Inf";
	string ans = "",p;
	int z,i,o;
	z = x / y;
	if(z)
		ans += to_string(z);//得到整数部分
	if (x%y)//分数
	{
		i = prime(x%y, y);//求公因子
		o = (x%y) / i;
		y /= i;
		//得到最简分数
		if (z)
			ans += " ";
		ans += to_string(o) + '/' + to_string(y);
	}
	if (ans.empty())
		ans = '0';
	return ans;
}
string fushu(string x)
{
	string c = "(-";
	c += x;
	c += ")";
	return c;
}
int main()
{
	int x, x1, y, y1;
	string a, b, c;
	f1 = false;
	x = init();
	x1 = init();
	f2 = f1;
	f1 = false;
	y = init();
	y1 = init();
	//输入结束
	a = pt(x, x1);
	b = pt(y, y1);
	if (f2)
		a = fushu(a);
	if (f1)
		b = fushu(b);
	if (f1 == f2)
		c = pt(x*y1 + x1*y, x1*y1);
	else 
	{
		c = pt(fabs(x*y1 - x1*y), x1*y1);
		if ((x*y1 - x1*y) < 0||f2)
			c = fushu(c);
	}
	cout << a << " + " << b << " = " << c << endl;
	if (f1 != f2)
	{
		c = pt(x*y1 + x1*y, x1*y1);
		if (f2)//第一个数为负数
			c = fushu(c);
	}
	else//符号相同的相减
	{
		c = pt(fabs(x*y1 - x1*y), x1*y1);
		if ((x*y1 - x1*y) < 0 && (!f1))//结果小于0但原本就是负数相减
			c = fushu(c);
	}
	cout << a << " - " << b << " = " << c << endl;
	c = pt(x*y, x1*y1);
	if (f1 != f2&&c != "0"&&c != "Inf")
		c = fushu(c);
	cout << a << " * " << b << " = " << c << endl;
	c = pt(x*y1, x1*y);
	if (f1 != f2&&c != "0"&&c != "Inf")
		c = fushu(c);
	cout << a << " / " << b << " = " << c << endl;
	system("pause");
	return 0;
}
