//hdu1242
/*
BFS+优先队列写法
存入所有可走的点，最先弹出时间花费最少的点进行计算
*/
#include<iostream>
#include<cstring>
#include<queue>  
using namespace std;
char graph[205][205];
int visit[205][205];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int n, m;
struct node
{
	int x, y;
	int time;	
	friend bool operator < (const node &a, const node &b)  //时间小的先出队  
	{
		return a.time>b.time;
	}
};
int Turn(int x, int y)//判断该点是否可走
{
	if (0 <= x && x<n && 0 <= y && y<m&&graph[x][y] != '#')
		return 1;
	return 0;
}
int bfs(int x, int y)//输入起始坐标
{
	int i;
	node cnt, next;
	priority_queue<node> que;  //定义一个优先队列
	memset(visit, 0, sizeof(visit));
	cnt.x = x;
	cnt.y = y;
	cnt.time = 0;
	visit[cnt.x][cnt.y] = 1;//标记该点
	que.push(cnt);//放入该点到优先队列
	while (!que.empty())//队列不空
	{
		cnt = que.top();
		que.pop();//取出首个元素
		if (graph[cnt.x][cnt.y] == 'r')//碰到了天使朋友
			return cnt.time;//最短时间确定
		for (i = 0; i<4; i++)//没碰到则移动
		{
			next.x = cnt.x + dir[i][0];
			next.y = cnt.y + dir[i][1];
			if (Turn(next.x, next.y) && !visit[next.x][next.y])
			{//判断该点是否可走，当前没有走过
				visit[next.x][next.y] = 1;//标记为走过
				if (graph[next.x][next.y] == 'x')//碰到守卫
					next.time = cnt.time + 2;
				else
					next.time = cnt.time + 1;
				que.push(next);//放入该点
			}
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	int i, j;
	int x, y, ans;
	while (cin>>n>>m)
	{
		for (i = 0; i<n; i++)
			cin>>graph[i];
		for (i = 0; i<n; i++)
			for (j = 0; j<m; j++)
				if (graph[i][j] == 'a')
				{
					x = i;
					y = j;//保持天使所在位置
					break;
				}
		ans = bfs(x, y);
		if (ans == -1)//出不来
			cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
