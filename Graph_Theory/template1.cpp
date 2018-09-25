//畅通工程，最小生成树自用模板
#include<iostream>
#include<algorithm>
using namespace std;
int link[101], m;
struct ct {
	int x;//村庄编号
	int y;
	int len;//路长
}a[50005];
bool cmp(const ct &a, const ct &b)
{
	return a.len < b.len;
}
bool bk()
{
	for (int i = 2; i <= m; i++)
		if (link[i - 1] != link[i])
			return false;
	return true;//已经全部连通
}
void un(int x, int y)//连接两条路
{
	int p = link[x];
	for (int i = 1; i <= m; i++)
		if (link[i] == p)
			link[i] = link[y];
}
int main()
{
	int n, i, ans;
	while (cin >> n >> m, n)
	{
		ans = 0;
		for (i = 0; i < n; i++)
			cin >> a[i].x >> a[i].y >> a[i].len;
		sort(a, a + n, cmp);
		for (i = 1; i <= m; i++)
			link[i] = i;
		for (i = 0; i < n; i++)
		{
			if (link[a[i].x] != link[a[i].y])//还未连接过的最短路线
			{
				un(a[i].x, a[i].y);
				ans += a[i].len;
			}
		}
		if (bk())
			cout << ans << endl;
		else
			cout << "?" << endl;
	}
	return 0;
}
