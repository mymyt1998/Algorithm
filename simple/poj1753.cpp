//枚举，最多有2^16次
#include<iostream>
using namespace std;
int check(int x, int m[6][6])
{
	int re = 0;//记录翻转次数
	for (int i = 1; i<5; i++)
		for (int j = 1; j < 5; j++)
		{
			if (x & 1)//末位为1则翻转
			{
				re++;
				m[i][j] = !m[i][j];
				m[i + 1][j] = !m[i + 1][j];
				m[i][j + 1] = !m[i][j + 1];
				m[i][j - 1] = !m[i][j - 1];
				m[i - 1][j] = !m[i - 1][j];
			}
			x = x >> 1;
		}
	int p = m[1][1];
	for (int i = 1; i < 5; i++)//判断是否成功
		for (int j = 1; j < 5; j++)
			if (p != m[i][j])
				return -1;
	return re;
}
int main()
{
	int i, j, map[6][6],m[6][6], ans, p;
	char c;
	for (i = 1; i < 5; i++)
		for (j = 1; j < 5; j++)
		{
			cin >> c;
			map[i][j] = c == 'b' ? 0 : 1;
		}
	ans = 0;
	p = 20;
	while (ans < 65536)
	{
		for (int i = 1; i < 5; i++)
			for (int j = 1; j < 5; j++)
				m[i][j] = map[i][j];
		i = check(ans, m);
		if (i != -1)//成功翻转
			p = (i < p)? i : p;//取最小值
		ans++;
		if (p == 0)
			break;
	}
	if (p != 20)
		cout << p << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}
