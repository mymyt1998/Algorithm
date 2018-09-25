//HDU2544
//最短路径之Floyd算法
#include <iostream>  
using namespace std;
const int INF = 0x3f3f3f3f;
int ans[110][110];
int main()
{
	int i, j, k, n, m, p, q, s;
	while (cin>>n>>m,n+m)
	{
		for (i = 1; i <= n; i++)
		{//所有点刚开始不连通，为INF
			for (j = 1; j <= n; j++)
			{
				ans[i][j] = INF;
			}
		}
		for (i = 0; i<m; i++)
		{
			cin>>p>>q>>s;//p,q城市的距离为s，双向
			ans[p][q] = ans[q][p] = s;
		}
		for (k = 1; k <= n; k++)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (ans[i][j]>ans[i][k] + ans[k][j])
					{
						ans[i][j] = ans[i][k] + ans[k][j];
					}//更新两点之间最短路
				}
			}
		}
		cout<<ans[1][n]<<endl;
	}
	return 0;
}
