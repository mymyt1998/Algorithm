//给出出栈顺序，求入栈顺序
#include<iostream>
#include<stack>
#include<string>
#include<queue>
using namespace std;
stack<int> x,y;
queue<int> ans;
string a, b;
int n, i;
bool backtrace(int dep)
{
	if (dep == n)
	{
		while (!x.empty() && !y.empty())
		{
			if (x.top() == y.top())
			{
				ans.push(0);
				x.pop();
				y.pop();
			}
			else
				break;
		}
		if (x.empty())
			return true;
		else
			return false;
	}
	x.push(a[dep]-'0');
	ans.push(1);
	while (!x.empty() && !y.empty())
	{
		if (x.top() == y.top())
		{
			ans.push(0);
			x.pop();
			y.pop();
		}
		else
			break;
	}
	backtrace(dep + 1);
}
int main()
{
	while (cin >> n)
	{
		cin >> a >> b;
		for (i = n-1; i >=0; i--)
		{
			y.push(b[i] - '0');
		}
		if (backtrace(0))
		{
			cout << "Yes." << endl;
			while (!ans.empty())
			{
				if (ans.front())
					cout << "in" << endl;
				else
					cout << "out" << endl;
				ans.pop();
			}
			cout << "FINISH" << endl;
		}
		else
			cout << "No.\nFINISH" << endl;
		while (!x.empty())
			x.pop();
		while (!y.empty())
			y.pop();
		while (!ans.empty())
			ans.pop();
	}
	return 0;
}
