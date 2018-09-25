//给顶点数，边数，边的起点终点，计算每条边的入度出度
//邻接表+逆邻接表
//记得释放内存
#include<iostream>
using namespace std;
struct node {
	int u;//终点
	node * next=NULL;
};
struct List {
	int data;
	node *head1=NULL;//出边表表头指针
	node *head2=NULL;//入边表表头指针
}Lg[101];
int main()
{
	int n, m, x, y, i;
	while (cin >> n >> m, n + m)//顶点数，边数
	{
		node *p;
		p = new node;
		for (i = 0; i < m; i++)
		{
			cin >> x >> y;
			x--, y--;
			p = new node;
			p->u = y;
			p->next = Lg[x].head1;
			Lg[x].head1 = p;//入边
			p = new node;
			p->u = x;
			p->next = Lg[y].head2;
			Lg[y].head2 = p;//出边
		}
		for (i = 0; i < n; i++)//输出出度
		{
			int re = 0;
			p = Lg[i].head1;
			while (p!=NULL)
			{
				re++;
				p = p->next;
			}
			if (i != n - 1)
				cout << re << " ";
			else
				cout << re << endl;
		}
		for (i = 0; i < n; i++)//输出入度
		{
			int re = 0;
			p = Lg[i].head2;
			while (p!=NULL)
			{
				re++;
				p = p->next;
			}
			if (i != n - 1)
				cout << re << " ";
			else
				cout << re << endl;
		}
		//释放邻接表
		for (i = 0; i < n; i++)
		{
			p = Lg[i].head1;
			while (p != NULL)
			{
				Lg[i].head1 = p->next;
				delete p;
				p = Lg[i].head1;
			}
			p = Lg[i].head2;
			while (p != NULL)
			{
				Lg[i].head2 = p->next;
				delete p;
				p = Lg[i].head2;
			}
		}
	}
	return 0;
}

//7 9 1 2 2 3 2 5 2 6 3 5 4 3 5 2 5 4 6 7 
//4 7 1 4 2 1 2 2 2 3 2 3 4 2 4 3  
