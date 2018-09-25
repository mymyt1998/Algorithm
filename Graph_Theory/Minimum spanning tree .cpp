//最小生成树之prim算法
//就是从一个起点开始进行连通，始终寻找没有访问过且最小的边来进行连通。
//最优
#include<iostream>  
#define maxn 115  
#define inf 200000005
int dis[maxn], vis[maxn];
int Map[maxn][maxn];
int n, sum;
using namespace std;
void prim() 
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i)  
		dis[i] = Map[i][0];

	vis[0] = 1;
	dis[0] = 0;

	for (int i = 0; i < n - 1; ++i)
	{ //n-1条边  
		int k, temp = inf; //temp用来找最小的边，k存储最小边的对应的点  
		for (int j = 0; j < n; ++j) 
		{
			if (!vis[j] && dis[j] < temp)//当前边为最小且没用被去过
				temp = dis[j], k = j;
		}
		vis[k] = 1;  //标记找到的点  
		sum += dis[k]; //最小边加入到最小生成树里面
		for (int j = 0; j <n; ++j)
			if (!vis[j] && dis[j] > Map[k][j])  
				dis[j] = Map[k][j]; //存储小的  
	}
	cout << sum << endl;
}
int main() 
{
	while (cin>>n) //农场的数量
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)//邻接矩阵
			{
				cin>> Map[i][j];//I农场到J农场距离，邻接矩阵存图  
			}
		sum = 0;
		prim();
	}
	return 0;
}
