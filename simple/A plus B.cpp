//大数相加
#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int T;
	cin >> T;
	char a[1000], b[1000], c[1001];
	int p = 0;  //进位标志
	int flag = 1,len_a, len_b;
	while (T--)
	{
		cin >> a >> b;
		cout << "Case " << flag++ << ":" << endl;
		cout << a << " + " << b << " = ";
		len_a = strlen(a) - 1;
		len_b = strlen(b) - 1;
		int i = 0;
		for (i = 0; len_a >= 0 || len_b >= 0; len_a--, len_b--, i++)
		{
			if (len_a >= 0 && len_b >= 0)
				c[i] = a[len_a] + b[len_b] - '0' + p;
			if (len_a >= 0 && len_b<0)
				c[i] = a[len_a] + p;
			if (len_a<0 && len_b >= 0)
				c[i] = b[len_b] + p;
			p = 0;
			if (c[i]>'9') 
			{
				c[i] = c[i] - 10;
				p = 1;
			}
		}
		if (p == 1)
			cout << p;
		while (i--)
			cout << c[i];
		if (T >= 1)
			cout << endl << endl;
		else
			cout << endl;
	}
	return 0;
}