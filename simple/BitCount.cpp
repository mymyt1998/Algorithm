//如何使最后一行的灯全部熄灭
//枚举+位运算
#include<iostream>
using namespace std;
char ols[5];
char lights[5];
char ans[5];
int GetBit(char c, int i)//取字符c的第i个比特
{
	return (c >> i) & 1;
}
void SetBit(char &c, int i, int v)//把字符c的第i位设置为v
{
	//(1<<i) 第i位为1，其他位都为0
	if (v)
		c |= (1 << i);
	else
		c &= ~(1 << i);
}
void FlipBit(char &c, int i)//翻转c的第i位
{
	c ^= (1 << i);
}
void OutputAns(int t, char Ans[])
{
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << GetBit(Ans[i], j);
			if (j < 5)
				cout << " ";
		}
		cout << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		for(int i=0;i<5;i++)
			for (int j = 0; j < 6; j++)
			{
				int s;
				cin >> s;
				SetBit(ols[i], j, s);
			}
		//枚举灯开关第一行所有可能的状态,第一行确定则所有行确定
		for (int n = 0; n < 64; ++n)
		{
			int switchs = n;//当前行的开关状态
			memcpy(lights, ols, sizeof(ols));
			for (int i = 0; i < 5; i++)//处理第i行的开关情况
			{
				ans[i] = switchs;//第一行开关状态
				for (int j = 0; j < 6; j++)
				{
					if (GetBit(switchs, j))
					{
						if (j > 0)
						{
							FlipBit(lights[i], j-1);
							FlipBit(lights[i], j);
							if (j < 5)
								FlipBit(lights[i], j + 1);
						}
					}
				}//对第i行的灯进行处理
				if (i < 5)//处理下一行
				{
					lights[i + 1] ^= switchs;//直接翻转
				}
				switchs = lights[i];
			}
			if (lights[4] == 0)
			{
				OutputAns(t, ans);
				break;
			}
		}
	}
	return 0;
}
