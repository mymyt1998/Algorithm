#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
struct tp {
	int x, y;
};
vector<tp> v;
set<int> node;//节点
int f[100005];
bool ans()
{
	int p,i;
	set<int>::iterator it;//定义迭代器常量
	for (it = node.begin(); it != node.end(); it++)
		f[*it] = *it;//并查集
	for (i = 0; i < v.size(); i++)
	{
		if (f[v[i].x] == f[v[i].y])//已经连接过
			return false;
		p = f[v[i].x];//将所有与x相连的节点变成y
		for (it = node.begin(); it != node.end(); it++)
			if (f[*it] == p)
				f[*it] = f[v[i].y];
	}
	set<int>::iterator t;//定义一个节点
	t = node.begin();
	for (it = node.begin(); it != node.end(); it++)//判断是否有多个树
		if (f[*t] != f[*it])
			return false;
	//判断是否有多个根结点
	memset(f, 0, sizeof(f));
	for (i = 0; i < v.size(); i++)
	{
		f[v[i].y]++;
		if (f[v[i].y] >= 2)
			return false;
	}
	return true;
}
int main()
{
	int n, m;
	int len = 0;
	int c = 0;
	while (cin >> n >> m, n >= 0 && m >= 0)
	{
		if (!(n + m))//0 0
		{
			cout << "Case " << ++c;
			if (ans())
				cout << " is a tree." << endl;
			else
				cout << " is not a tree." << endl;
			v.clear();
			node.clear();
		}
		else
		{
			tp p;
			p.x = n;
			p.y = m;
			v.push_back(p);//存放所有边
			node.insert(n);//存放所有节点序号
			node.insert(m);
		}
	}
	return 0;
}
