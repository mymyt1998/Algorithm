#include<iostream>
#include<cstring>
using namespace std;
int f[1005][1005];//当取前i个石头时所得的最大值
int main()
{
	int t, n, v, value[1005], sz[1005], i, j;
	cin >> t;
	while (t--)
	{
		cin >> n >> v;//几个石头， 容量
		memset(f, 0, sizeof(f));
		for (i = 1; i <= n; i++)
			cin >> value[i];
		for (i = 1; i <= n; i++)
			cin >> sz[i];
		for (i = 1; i<=n; i++)
			for (j = 0; j <= v; j++)
			{
				if (sz[i] <= j)
				{
					if (value[i] + f[i - 1][j - sz[i]] > f[i - 1][j])
						f[i][j] = value[i] + f[i - 1][j - sz[i]];
					else
						f[i][j] = f[i - 1][j];
				}
				else
					f[i][j] = f[i - 1][j];
			}
		cout << f[n][v] << endl;
	}
	return 0;
}
