//判断a+b是否大于c
#include<iostream>
#include<string>
using namespace std;
int flag;
int ck()
{
	string a, b, c;
	cin >> a >> b >> c;
	int A[12], B[12], C[12];
	int l1, l2, l3;
	l1 = a.length();
	l2 = b.length();
	l3 = c.length();
	for (int i = 0; i < 11; i++)
		A[i] = B[i] = C[i] = 0;
	for (int i = 9;i >= 0 ; i--)
	{
		if (l1 > 0)
			A[i] = a[--l1] - '0';
		if (l2 > 0)
			B[i] = b[--l2] - '0';
		if (l3 > 0)
			C[i] = c[--l3] - '0';
	}
	if (((a[0] + b[0]) == (int('-') * 2)) || (c[0] == '-'))
		flag = 1;
	for (int i = 0; i < 10; i++)
	{
		if ((A[i] + B[i]) == C[i])
			continue;
		if ((A[i] + B[i]) > C[i])
			return 1;
		else
			return 0;
	}
	return 0;
}
int main()
{
	int t, i = 0;
	cin >> t;
	getchar();
	while (t--)
	{
		flag = 0;
		if ((ck()) ^ (flag))
			cout << "Case #" << ++i << ": true" <<endl;
		else
			cout << "Case #" << ++i << ": false"<<endl;
	}
	return 0;
}
