//丑数，不能被2，3，5以外的其他素数整除的数，求第1500个丑数
//优先队列，每次取出最小的丑数来生成新的3个丑数
//一个丑数有多种生成方法，需要判断
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int coeff[3] = { 2,3,5 };
struct cmp {
	bool operator()(LL a, LL b)
	{
		return a > b;
	}
};
int main()
{
	priority_queue<LL, vector<LL>, cmp> q;//优先级高先出队，设置最小的优先级最高
	set<LL> s;//存所有丑数
	q.push(1);
	s.insert(1);
	for(int i=1;;i++)
	{
		LL x = q.top();
		q.pop();//取出最小数
		if (i == 1500)
		{
			cout << "The 1500'th ugly number is : " << endl;
			cout<<x << endl;
			break;
		}
		for (int j = 0; j < 3; j++)
		{
			LL x2 = x*coeff[j];
			if (!s.count(x2))//没有存入
			{
				s.insert(x2);
				q.push(x2);
			}
		}
	}
	return 0;
}
