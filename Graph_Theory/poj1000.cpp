/*使用贪心和递归方法，从每一行开始对每个元素进行检查，如果是0（反面），
则对以该点作为 M * M的左上角进行反转，使得当前元素变为1
注意： M *M 已越界，并且还存在0元素，则判定为无法实现，输出-1*/
#include<iostream>
#include<algorithm>
using namespace std;
int a[1001][1001], n, m, ans;
bool ck(int x)//检查当前行是否都为1 
{
	for (int i = 0; i<n; i++)
		if (!a[x][i])
			return false;
	return true;
}
/*
4 2
1 1 0 0
0 0 1 1
1 1 1 1
0 0 0 0
*/
bool dfs(int x, int y)//已经到了哪一点 
{
	if (x == n)
		return true;
	if (y == n)//当前行结束
	{
		if (!ck(x))
			return false;//还有0
		dfs(x + 1, 0);
	}
	else
	{
		if (a[x][y])
			dfs(x, y + 1);
		else//碰到0 0 2 2 3
		{
			if (x + m <= n && y + m <= n)//没有越界
			{
				for (int p = x; p<x + m; p++)
					for (int q = y; q<y + m; q++)
						a[p][q] = !a[p][q];
				ans++;
				dfs(x, y + 1);
			}
			else
				return false;
		}
	}
}
int main()
{
	int i, j;
	while (cin >> n >> m)
	{
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				cin >> a[i][j];
		ans = 0;
		if (dfs(0, 0))
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
