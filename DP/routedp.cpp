//路线类dp
//找权值最大的路线
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF -0x3f3f3f3f
int main()
{
	int c, n, m, a[25][1005],i,j;
	long long dp[25][1005],M;//记录到达该点最多获得多少能量
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		memset(dp, INF, sizeof(dp));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				cin >> a[i][j];
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)//a[1][3]
			{
				dp[i][j] = a[i][j];//10
				if (i == 1 && j == 1)
					continue;
				M = max(dp[i - 1][j], dp[i][j-1]);
				for (int k = 1; k <j; k++)//找左移的点
					if (j%k == 0)
						M = max(M, dp[i][k]);
				dp[i][j] += M;
			}
		cout << dp[n][m] << endl;
	}
	return 0;
}
