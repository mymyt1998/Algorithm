//最简单的DP
//求子序列的最大和，起始位置，初始位置
#include<iostream>
using namespace std;
int main()
{
	int n, T, a, sta, end, max, k, i, p, sum;
	cin>>T;
	for (p = 1; p <= T; p++) 
	{
		cin>>n;
		max = -9999; //先变成最小值 
		sum = 0;  //表示某段连续和  
		sta = end = k = 1; //sta最大和的开始,end最大和的结束,k记录每次求和的开始
		for (i = 1; i <= n; i++) 
		{
			cin>>a;
			sum += a;
			if (sum>max)
			{   //记录最大连续和的值  
				max = sum;
				sta = k;
				end = i;
			}
			if (sum<0)//如果前面的是负数，干脆不要了
			{
				sum = 0;
				k = i + 1;
			}
		}
		if (p != 1)
			cout << endl;
		cout<<"Case "<<p<<":"<<endl;
		cout << max << " " << sta << " " << end<<endl;
	}
	return 0;
}