/*
http://www.lanqiaotiku.com/341.html
dfs搜索题。
按深度优先搜索的思路从左上角开始搜索，
累加当前数字，
直到数字和为所有数字和的一半，
返回走到当前的步数。
*/
#include<iostream>
using namespace std;
int a[10][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool isv[10][10];
int m, n, sum;
bool out(int x,int y,int num)
{
	if (x<1 || y<1 || x>n || y>m)//越界
		return true;
	if (isv[x][y])//已经访问过
		return true;
	if (num + a[x][y] > sum / 2)//和超过了总数的一半
		return true;
	return false;
}
int dfs(int x, int y, int num)
{
	if (num == sum / 2)
		return 1;//左上角位置的数正好是总和的一半
	for (int i = 0; i < 4; i++)
	{
		//nx,vy表示移动到的新位置
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (out(nx, ny, num))//该位置不能走
			continue;
		//能走就继续往后走
		isv[nx][ny] = true;//标记为能走
		int rest = dfs(nx, ny, num + a[nx][ny]);
		if (rest)//产生了结果
			return rest + 1;
		//没产生结果则这条路不走
		isv[nx][ny] = false;
	}
	return 0;
}
int main()
{
	int i, j;
	while (cin >> m >> n)
	{
		sum = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				sum += a[i][j];
			}
		if (!sum & 1)
			cout << 0 << endl;
		else
		{
			memset(isv, 0, sizeof(isv));//全标记未走
			isv[1][1] = true;//该点必走
			cout << dfs(1, 1, a[1][1]) << endl;
		}
	}
	return 0;
}
