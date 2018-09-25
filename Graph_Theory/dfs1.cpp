/*
经典dps
从起点到终点是否能刚好走t步，X代表墙
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char map[10][10];
int dir[4][2] = { 0,1,1,0,-1,0,0,-1 }, n, m, t,ex,ey;
bool dfs(int x, int y, int dep)
{
	if (dep == t && x==ex&&y==ey)//成功
		return true;
	if (x >= n || y >= m || x < 0 || y < 0)//越界
		return false;
	int dis = fabs(x - ex) + fabs(y - ey);//记录该点到终点距离
	dis = t - dep - dis;//剩余的时间不能走到
	if (dis < 0 || dis &1)
		return false;//剪枝
	for (int i = 0; i < 4; i++)
	{
		if (map[x + dir[i][0]][y + dir[i][1]] != 'X')//可走
		{
			map[x + dir[i][0]][y + dir[i][1]] = 'X';
			if (dfs(x + dir[i][0], y + dir[i][1], dep + 1))
				return true;
			map[x + dir[i][0]][y + dir[i][1]] = '.';
		}
	}
	return false;
}
int main()
{
	int  i, j,sx,sy;
	while (cin >> n >> m >> t,n+m+t)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')//记录起点
					sx = i, sy = j;
				if (map[i][j] == 'D')//记录终点
					ex = i, ey = j;
			}
		if (dfs(sx, sy, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
