//递归版二分查找
#include<iostream>
#include<cstdlib>
#define Max 10001
using namespace std;
int a[Max], key;

int search(int start, int last)
{
	int mid;
	if (last >= start)
	{
		mid = (last + start)/2;//取中间值
		if (key == a[mid])//找到了
		{
			cout << mid << endl;
			return 0;
		}
		else if (key < a[mid])
			search(start, mid - 1);
		else
			search(mid + 1, last);
	}
	else
	{
		cout << "-1\n";
		return 0;
	}
}
int main()
{
	int n;
	while (cin >> n)//元素个数
	{
		for (int i = 1; i <= n; i++)
			cin >> a[i];//已经从小到大排序
		cin >> key;//需要查找的元素
		search(1, n);//起始地址，终止地址
	}
	return 0;
}