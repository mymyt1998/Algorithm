#include<iostream>
using namespace std;
int  pre[1050];
bool t[1050];//t用于标记独立块的根结点
int Find(int x)
{
	int r = x;
	while (r != pre[r])
		r = pre[r];
	int i = x, j;
	while (pre[i] != r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void mix(int x, int y)
{
	int fx = Find(x), fy = Find(y);
	if (fx != fy)
	{
		pre[fy] = fx;
	}
}

int main()
{
	int N, M, a, b, i, j, ans;
	while (cin>>N>>M, N)
	{
		for (i = 1; i <= N; i++) //初始化 
			pre[i] = i;
		for (i = 1; i <= M; i++) //整理数据 
		{
			cin>>a>>b;
			mix(a, b);
		}
		memset(t, 0, sizeof(t));
		for (i = 1; i <= N; i++)//标记根结点
		{
			t[Find(i)] = 1;
		}
		for (ans = 0, i = 1; i <= N; i++)
			if (t[i])
				ans++;
		cout << ans - 1 << endl;
	}
	return 0;
}
