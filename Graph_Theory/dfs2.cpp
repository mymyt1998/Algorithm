#include<iostream>
using namespace std;
int link[11][4] = {
	{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},{1,1,0,0},{0,0,1,1},{1,0,1,1,},{1,1,1,0},{0,1,1,1},{1,1,0,1},{1,1,1,1}
};//上下左右四个方向的连通情况
int dir[4][2] = { -1,0,1,0,0,-1,0,1 };//往上下左右移动
int p[4] = { 1,0,3,2 };//相反方向
char map[55][55];
int m, n;
void bfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n)//越界
		return;
	int c = map[x][y] - 'A';//当前水管方向
	map[x][y] = 'X';//已走过
	for (int i = 0; i < 4; i++)
	{
		if (link[c][i])//可以往该方向去
		{
			int nc = map[x + dir[i][0]][y + dir[i][1]] - 'A';//该方向的图水管
			if (link[nc][p[i]])
				bfs(x + dir[i][0], y + dir[i][1]);
		}
	}
}
int main()
{
	int i, j, ans;
	while (cin >> m >> n, m >= 0 && n >= 0)
	{
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				cin >> map[i][j];
		ans = 0;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (map[i][j] != 'X')//已经连通
					bfs(i, j), ans++;
		cout << ans << endl;
	}
	return 0;
}
