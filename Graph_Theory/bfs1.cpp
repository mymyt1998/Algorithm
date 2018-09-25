//hdu1242
/*
BFS搜索可走的路径
用矩阵存到各位置最少时间DP
从某个位置出发判断是否需要将它的相邻位置(x,y)入队列时，条件是这种走法比之前
走到(x,y)位置所花时间更少；如果所花时间更少，则(x,y)位置会重复入队列，但不会无穷下去
因为到达(x,y)位置的最少时间肯定是有下界的
*/
#include<iostream>
#include<queue>
using namespace std;
struct point {
	int x, y;
	int time;
};
queue<point> que;//当前朋友处于的位置
int n, m;
char graph[205][205];
int cost[205][205];//走到每个位置最少需要的时间
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
int ei, ej;//angel所处的位置
int bfs(point s)//从s位置开始搜索
{
	que.push(s);
	point cnt;
	while (!que.empty())
	{
		cnt = que.front();//取出最先存入的元素
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = cnt.x + dir[i][0];
			int y = cnt.y + dir[i][1];
			if (x >= 0 && x < n&&y >= 0 && y < m&&graph[x][y] != '#')
			{
				point next;
				next.x = x;
				next.y = y;
				next.time = cnt.time + 1;
				if (graph[x][y] == 'x')
					next.time++;
				if (next.time < cost[x][y])
				{
					cost[x][y] = next.time;
					que.push(next);
				}
			}
		}
	}
	return cost[ei][ej];
}
int main()
{
	while (cin >> n >> m)
	{
		int si, sj;
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				cost[i][j] = INT_MAX;//朋友到达每个点所花费的最少时间
				cin>>graph[i][j];
				if (graph[i][j] == 'a')
					ei = i, ej = j;
				if (graph[i][j] == 'r')
					si = i, sj = j;
			}
		int ans = INT_MAX;
		point start;
		start.time = 0;
		start.x = si;
		start.y = sj;
		ans = bfs(start);
		if (ans < INT_MAX)
			cout << ans << endl;
		else
			cout << "Poor ANGEL has to stay in the prison all his life." << endl;
	}
	return 0;
}
