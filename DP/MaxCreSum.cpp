//求最大递增子段和
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n, i, a[1005], j,ans;
	int dp[1005];//以a[i]结尾的最大序列和
	while (cin >> n, n)
	{
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i++)
		{
			cin >> a[i];
			dp[i] = a[i];
		}
		ans = a[1];
		for (i = 1; i <= n; i++)
		{//找到上一个可以连接的位置
			for (j=0;j<i;j++)
				if (a[j] < a[i])
					dp[i] = max(dp[j] + a[i],dp[i]);//注意负数情况,即使递增也要排除
			if (dp[i] > ans)
				ans = dp[i];
		}
		cout << ans << endl;
	}
	return 0;
}
