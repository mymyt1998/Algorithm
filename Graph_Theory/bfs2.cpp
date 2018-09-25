//蛇和梯子游戏(Snakes & Ladders)
/*
用一维数组存当前位置的跳转
遍历每个结点
*/
#include<iostream>
#include<queue>
using namespace std;
struct node{
	int y;//当前位置
	int cost;//投掷的次数
	friend bool operator < (const node &a,const node &b){
		return a.cost > b.cost;
	}
};
int to[405],n;
bool visit[405];
int bfs()
{
	priority_queue<node> que;
	node cnt;
	memset(visit, 0, sizeof(visit));
	cnt.cost = 0;
	cnt.y = 1;
	visit[1] = 1;
	que.push(cnt);
	while (!que.empty())
	{
		cnt = que.top();
		que.pop();
		if (cnt.y == n * n)
			return cnt.cost;
		for (int i = 1; i <= 6; i++)
		{
			if (visit[to[cnt.y + i]] || to[cnt.y + i] > n*n)
				continue;
			visit[to[cnt.y + i]] = 1;
			node tmp;
			tmp.cost = cnt.cost + 1;
			tmp.y = to[cnt.y + i];
			que.push(tmp);
		}
	}
	return -1;
}
int main()
{
	int d, s, l, i,x;
	cin >> d;
	while (d--)
	{
		cin >> n >> s >> l;
		for (i = 1; i <= n*n; i++)
			to[i] = i;
		for (i = 0; i < s + l; i++)
		{
			cin >> x;
			cin >> to[x];
		}
		cout << bfs() << endl;
	}
	return 0;
}
