#include<iostream>
#include<cstring>
using namespace std;
char map[25][25];
int vis[25][25];
int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
int w, h, ans;
/*
void DFS(int p, int q)//其他人的
{
	if (p <= m - 1 && p >= 0 && q >= 0 && q <= n - 1 && graph[p][q] == '.')
	{
		ans++;
		map[p][q] = '#';
	}
	else
	{
		return;
	}
	DFS(p - 1, q);
	DFS(p, q - 1);
	DFS(p, q + 1);
	DFS(p + 1, q);
}
*/
void dfs(int x, int y)//我的
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int t = x + dir[i][0];
		int e = y + dir[i][1];
		if (t < 0 || e < 0 || t >= h || e >= w)//越界
			continue;
		if (map[t][e] != '#')
		{
			map[t][e] = '#';
			dfs(t, e);
		}
	}
}
int main()
{
	while (cin >> w >> h, w + h)
	{
		int st, se, i, j;
		memset(vis, 0, sizeof(vis));
		for (i = 0; i<h; i++)
			for (j = 0; j < w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '@')
					st = i, se = j;
			}
		dfs(st, se);
		ans = 0;
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
				if (vis[i][j])
					ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
