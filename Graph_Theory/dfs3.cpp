//ZOJ1008
//DFS+剪枝
//需要统计重复矩阵
#include<iostream>
#include<cstring>
using namespace std;
int map[30][4], n, l, k;//正方形的四个边
int local[6][6];//每次放置的正方形
int num[30];//还剩多少个
bool dfs(int x, int y, int dep)//放置位置，已经放了多少个
{
	if (dep == n)//所有的都安排妥当
		return true;
	bool re;
	for (int i = 0; i<k; i++)
		if ((x == 0) || (map[local[x - 1][y]][2] == map[i][0]))//上边
		{
			if ((y == 0) || (map[local[x][y - 1]][1] == map[i][3]))//左边
			{
				if (num[i] > 0)//还有这种正方形
				{
					local[x][y] = i;
					num[i]--;
					if (y + 1 < l)
						re = dfs(x, y + 1, dep + 1);
					else
						re = dfs(x + 1, 0, dep + 1);
					if (re)
						return true;
					else
						num[i]++;
				}
			}
		}
	return false;
}
int main()
{
	int  cas = 1, i, j,p;
	ios::sync_with_stdio(false);
	while (cin >> n, n)
	{
		k = 0;
		l = n;//边界
		n *= n;//正方形数目
		for (i = 0; i < n; i++)
			num[i] = 1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 4; j++)
				cin >> map[k][j];
			for (p = 0; p < k; p++)
				if (map[p][0] == map[k][0] && map[p][1] == map[k][1] && map[p][2] == map[k][2] && map[p][3] == map[k][3])
				{
					num[p]++;
					break;
				}
			if(p==k)
				k++;
		}
		if (cas != 1)
			cout << endl;
		cout << "Game " << cas++ << ": ";
		if (dfs(0, 0, 0))//放置起点，一共放了多少个
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}
