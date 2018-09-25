//求大数a/b
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, c = "";
	int b, p, r = 0;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		p = int(a[i] - '0') + r * 10;
		r = p % b;
		if (i == 0 && p / b == 0)
			continue;
		c.append(1, char(p / b + 48));
	}
	cout << c << " " << r << endl;
	return 0;
}
/*把除法转换为求商过程的逆转,比如 100/2 等价于 1/2 商为0,余数为1,
商为0的情况下不能输输出, 然后余数和下一位 即0 组合为1*10+0=10,就变成10/2 商为5余数为0,
此时输出商数。然后0和下一位0组合为0*10+0=0 0/2余数为0,此时运算完毕。*/
