//求出现次数最多的字符串
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int n,max;
	string s,r;
	map<string, int> m;//字符串，个数
	while (cin >> n, n)
	{
		max = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			m[s]++;
			if (m[s] > max)
			{
				max = m[s];
				r = s;//用来记录出现次数最大的字符串
			}
		}
		cout << r << endl;
		m.clear();
	}
	return 0;
}