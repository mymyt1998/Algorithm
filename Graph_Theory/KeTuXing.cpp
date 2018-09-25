//根据顶点度数构造邻接矩阵，判断可图性
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct tx {
	int u;//顶点编号
	int deg;//度数
}a[15];
bool cmp(const tx &a, const tx &b)
{
	return a.deg > b.deg;
}
int main()
{
	int n, t, i, j, Edge[15][15],sum;
	while (cin >> t)
	{
		while (t--)
		{
			bool flag = false;//可图
			cin >> n;//顶点数
			memset(Edge, 0, sizeof(Edge));
			for (i = 0; i < n; i++)
				cin >> a[i].deg, a[i].u = i;
			for (i = 0; i < n; i++)//5 4 3 2 2 1 1 1 
			{
				sum = 0;
				for (j = i; j < n; j++)
					sum += a[j].deg;
				if (sum == 0)//已经成功
					break;
				sort(a+i, a + n, cmp);
				int p = a[i].deg;
				for (j = i+1; j <= i + p; j++)
				{
					a[j].deg--;
					if (a[j].deg < 0)//出现负数不可图
					{
						flag = true;
						break;
					}
					Edge[a[i].u][a[j].u] =Edge[a[j].u][a[i].u]= 1;//将当前位于ij的点相连
				}
				if (flag)
					break;
			}
			if (flag)
				cout << "NO" << endl<<endl;
			else
			{
				cout << "YES" << endl;
				for (i = 0; i < n; i++)
				{
					cout << Edge[i][0];
					for (j = 1; j < n; j++)
						cout << " " << Edge[i][j];
					cout << endl;
				}
				cout << endl;
			}
		}
	}
	return 0;
}
