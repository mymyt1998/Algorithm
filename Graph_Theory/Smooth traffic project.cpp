//HDU 1879 畅通工程
//最小生成树
#include<iostream>
#include<cstdio>//用cin就超时。。
#include<algorithm>
using namespace std;
int co[101], n, k;
struct t {
	int x, y, cost;
}a[5000];
bool cmp(const t &a, const t &b)//按成本对道路进行排序
{
	return a.cost < b.cost;
}
int find(int x)//用来寻找并查集父结点
{
	return co[x] == x ? x : find(co[x]);
}
void un(int x, int y)//合并两个并查集
{
	int a = find(x);
	int b = find(y);
	co[b] = a;
}
int main()
{
	std::ios::sync_with_stdio(false);//取消cin于stdin的同步
	int i, tp, r, c,z;
	while (scanf_s("%d",&n), n)
	{
		for (i = 1; i <= n; i++)
			co[i] = i;//初始化并查集
		z = n*(n - 1) / 2;
		for (i = 0; i <z ; i++)
		{
			scanf_s("%d%d%d%d",&a[i].x,& a[i].y,& a[i].cost ,& tp);
			if (tp)//直接将已修的路cost改为0
				a[i].cost = 0;
		}
		sort(a, a + z, cmp);
		for (i = 0, r = 0, c = 0; i < z; i++)
		{
			if (c == n - 1)//构成最小生成树
				break;
			if (find(a[i].x) != find(a[i].y))//两个城市不在同一并查集
			{
				un(a[i].x, a[i].y);//放入并查集
				r += a[i].cost;
				c++;
			}
		}
		cout << r << endl;
	}
	return 0;
}