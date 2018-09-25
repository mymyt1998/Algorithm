//将科学计数法转化为普通计数法
#include<iostream>
#include<string>
using namespace std;
int main()
{
	bool flag;
	int i,e,L;
	string s,ans,c;
	while (cin >> s)
	{
		if (s[0] == '-')
			c=ans = s[0];
		else
			c=ans = "";
		s.erase(0, 1);
		for (L = i = 0; i < s.length(); i++)//确定数值
		{
			if (s[i] == '.')
				continue;
			if (s[i] == 'E')
				break;
			ans += s[i];
			L++;//记录数的个数
		}
		if (s[i + 1] == '-')//判断指数正负
			flag = false;
		else
			flag = true;
		for (e =0,i = i + 2; i < s.length(); i++)//求出指数
		{
			e *= 10;
			e += s[i] - '0';
		}
		if (flag)//正数
		{
			if ((L - 1) > e)
				ans.insert(e+1, 1, '.');
			else if ((L - 1) < e)
			{
				e -= L - 1;
				while (e--)
				{
					ans += '0';
				}
			}
			cout << ans << endl;
		}
		else//负数
		{
			c += "0.";
			e--;
			while (e--)
			{
				c += '0';
			}
			if (ans[0] == '-')
				ans.erase(0, 1);
			c += ans;
			cout << c << endl;
		}
	}
	return 0;
}
