//上方的两个木块尺寸都严格小于下方木块
//求最高
//hdu1069
//优化成DP，全排列枚举所有可能出现的情况
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct ct {
	int high;
	int x;
	int y;
}a[1010];//所有可能的放法
bool cmp(const ct &a, const ct &b)
{
	if (a.x == b.x)
		return a.y > b.y;
	return a.x > b.x;
}
int main()
{
	int n, i, b[3], j, Max;
	int dp[1010];//前i个木块所得到的最大值
	int c = 0;
	while (cin >> n, n)
	{
		int len = 0;
		for (i = 0; i < n; i++)
		{
			cin >> b[0] >> b[1] >> b[2];
			sort(b, b + 3);
			do
			{
				a[len].high = b[0];
				a[len].x = b[1];
				a[len].y = b[2];
				len++;
			} while (next_permutation(b, b + 3));//将3个尺寸全排列存入
		}
		sort(a, a + len, cmp);//按尺寸从大到小排队
		Max = 0;
		for (i = 0; i<len; i++)//必须放第i个木块
		{
			dp[i] = a[i].high;
			for (j = 0; j < i; j++)
				if ((a[j].x > a[i].x)&&(a[j].y > a[i].y))
					dp[i] = max(dp[i], dp[j] + a[i].high);
			//可以放i木块的所有情况
			Max = max(Max, dp[i]);
		}	
		cout << "Case " << ++c << ": maximum height = ";
		cout << Max << endl;
	}
	return 0;
}
