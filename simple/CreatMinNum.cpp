//用给定的数字构成最小的数，必须全部用到
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,a[10],p;
	string s;
	for (i = 0; i < 10; i++)
	{
		cin >> a[i];
		p = a[i];
		while (p--)
		{
			s += '0' + i;
		}
	}
	p=i = 1;
	if (a[0])//存在0
	{
		while (!a[i])//找到非0最小的数
		{
			p = i;
			i++;
		}
		s.erase(a[0],1);
		s.insert(0 ,1,'0' + p);
	}
	cout << s << endl;
	return 0;
}
