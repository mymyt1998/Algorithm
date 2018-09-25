/*给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。
例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；
如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。*/
#include<iostream>
using namespace std;
int start, len, inputLen, k, lenPrint;
int num[100100]; //在某个地址i存的数值是多少
int nex[100100]; //链表第i个元素的下一个元素地址是多少
int To[100100]; //存储待反转的一组k个元素
void print(int ptr)
{
	//对于第一行，地址只用输出一遍；以后都从上一行的nex开始，要输出两遍地址
	if (lenPrint == 0)
		printf("%05d %d ", ptr, num[ptr]);
	else
		printf("%05d\n%05d %d ", ptr, ptr, num[ptr]);
	lenPrint++;
}
void count() 
{
	//统计链表的真正长度
	int now = start;
	len = 0;
	while (now != -1)
	{
		now = nex[now];
		len++;
	}
}
int main() 
{
	cin >> start >> inputLen >> k;
	int p, now = start, t1, t2;
	for (int i = 0; i < inputLen; i++)
	{
		cin >> p >> t1 >> t2;
		if (p >= 0 && p <= 99999 && num[p] == 0)
		{
			num[p] = t1;
			nex[p] = t2;
		}
	}
	count();
	//每一个待反转的段
	for (int i = 0; (i + 1) * k <= len; i++)
	{
		for (int j = 0; j < k; j++)
		{
			To[j] = now;
			now = nex[now];
		}
		for (int j = k - 1; j >= 0; j--)
			print(To[j]);
	}

	//最后剩下未反转的部分
	for (int j = (len / k) * k; j < len; j++)
	{
		print(now);
		now = nex[now];
	}
	printf("-1\n");
	return 0;
}
