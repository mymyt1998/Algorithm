//最小生成树，并查集
#include<iostream>
using namespace std;
#define INF 9999999
int link[105];
bool ck(int n)//全部连接则退出循环
{
	for (int i = 2; i <= n; i++)
		if (link[i - 1] != link[i])
			return true;
	return false;
}
int main()
{
	int n, dist[105][105], i, j, q, x, y, p;
	while (cin >> n)
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> dist[i][j];//i和j村庄的距离
		for (i = 0; i <= n; i++)//还未连接
			link[i] = i;
		cin >> q;//已经连通的路线数
		for (i = 0; i < q; i++)
		{
			cin >> x >> y;
			p = link[x];
			for (j = 1; j <= n; j++)
				if (link[j] == p)
					link[j] = link[y];
		}
		int Min = INF;
		int ans = 0;
		x = y = 0;
		while (ck(n))//还没有全部连接
		{
			for (i = 1; i <= n; i++)//找出最小连接路线
				for (j = 1; j < i; j++)
					if( (dist[i][j] < Min)&&link[i]!=link[j])
					{
						Min = dist[i][j];
						x = i;
						y = j;
					}
			ans += Min;
			p = link[x];
			for (int k = 1; k <= n; k++)
				if (link[k] == p)
					link[k] = link[y];
			Min = INF;
		}
		cout << ans << endl;
	}
	return 0;
}
