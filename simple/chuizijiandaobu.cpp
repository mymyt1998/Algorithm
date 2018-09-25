//C代表“锤子”、J代表“剪刀”、B代表“布”
#include<iostream>
#include<map>
using namespace std;
bool iswin(char x, char y)
{
	if (x == 'C'&&y == 'J')
		return true;
	if (x == 'J'&&y == 'B')
		return true;
	if (x == 'B'&&y == 'C')
		return true;
	return false;
}
int main()
{
	int n,a[3],b[3],mx1,mx2;//胜、平、负次数
	char x, y, an1, an2;//an记录胜的最多的字符
	map<char, int> m1,m2;
	while (cin >> n)
	{
		a[0] = a[1] = a[2] = b[0] = b[1] = b[2] = 0;
		m1['J'] = m1['B'] = m1['C'] = 0;
		m2['J'] = m2['B'] = m2['C'] = 0;
		while (n--)
		{
			cin >> x >> y;
			if (x == y)//平
			{
				a[1]++;
				b[1]++;
				continue;
			}
			if (iswin(x, y))//赢
			{
				a[0]++;
				b[2]++;
				m1[x]++;
			}
			else//输
			{
				a[2]++;
				b[0]++;
				m2[y]++;
			}
		}
		cout << a[0] << " " << a[1] << " " << a[2]<<endl;
		cout << b[0] << " " << b[1] << " " << b[2] << endl;
		mx1 = mx2 = -1;
		map<char, int>::iterator it;
		for (it = m1.begin(); it != m1.end(); it++)
			if (mx1 < (*it).second)
				mx1 = (*it).second, an1 = (*it).first;
		for (it = m2.begin(); it != m2.end(); it++)
			if (mx2 < (*it).second)
				mx2 = (*it).second, an2 = (*it).first;
		cout << an1 << " " << an2 << endl;
	}
	return 0;
}
//PAT
