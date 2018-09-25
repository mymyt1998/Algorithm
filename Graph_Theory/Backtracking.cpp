//BFS+优先队列（回溯）
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define N 105
int n, m;
int path[N][N];//记录路径方向 0 1 2 3 上下左右
int Visit[N][N];//记录是否走过
int Map[N][N];
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
struct node {
	int x, y;
	int time;
	node(int x, int y, int time)//构造方法，方便建立新点
	{
		this->x = x;
		this->y = y;
		this->time = time;
	}
};
//比较方式
struct quecmp {
	bool operator()(const node &a, const node &b)
	{//具有最高优先级的元素最先删除
		return a.time > b.time;
	}
};
int bfs()
{
	memset(path, -1, sizeof(path));
	priority_queue<node, vector<node>, quecmp> prq;//优先队列<类型，使用的容器（数组类vector,queue），比较方式>默认队头元素最大
	prq.push(node(0, 0, 0));//起点，开始的用时
	Visit[0][0] = -1;//标记为已走过
	while (!prq.empty())
	{
		node tmp = prq.top();//取出当前点
		prq.pop();
		if (tmp.x == n - 1 && tmp.y == m - 1)//到达终点
			return tmp.time;
		for (int i = 0; i < 4; i++)//尝试走到下一个点
		{
			int x = tmp.x + dir[i][0];
			int y = tmp.y + dir[i][1];
			//判断该点是否可走
			if (Visit[x][y] != -1 && x >= 0 && y >= 0 && x < n&&y < m)
			{
				int t = Visit[x][y] + 1 + tmp.time;
				prq.push(node(x, y, t));
				path[x][y] = i;//记录当前点是怎么走到的
				Visit[x][y] = -1;
			}
		}
	}
	return 0;
}

int tt;
void output(int x,int y)//坐标
{
	//当前点的上一步
	int fx = x - dir[path[x][y]][0];
	int fy = y - dir[path[x][y]][1];
	if (x == 0 && y == 0)
		return;//到达起点
	output(fx, fy);
	cout << ++tt << "s:(" << fx << "," << fy << ")->(" << x << "," << y << ")" << endl;
	while (Map[x][y]-- > 0)
		cout << ++tt << "s:FIGHT AT (" << x << "," << y << ")" << endl;
}
int main()
{
	while (cin >> n >> m)
	{
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				char c;
				cin >> c;
				if (c == 'X')
					Visit[i][j] = -1;//不可走
				else if (c == '.')
					Visit[i][j] = 0;
				else
					Visit[i][j] = c - '0';
				Map[i][j] = Visit[i][j];//备份地图
			}
		int ans = bfs();
		if (ans)
		{
			tt = 0;
			cout << "It takes " << ans << " seconds to reach the target position, let me show you the way." << endl;
			output(n - 1, m - 1);
		}
		else
			cout << "God please help our poor hero." << endl;
		cout << "FINISH" << endl;
	}
	return 0;
}
