#include<iostream>
#include<algorithm>
using namespace std;
struct t {
	int no;
	int de;
	int cai;
	int sum;
	int age;
}a[100005];
bool cmp(const t &a, const t &b)
{
	if (a.age != b.age)
		return a.age > b.age;
	else if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.de != b.de)
		return a.de > b.de;
	else
		return a.no < b.no;
}
int main()
{
	int n, l, h, i, x, y, z, k;
	cin >> n >> l >> h;
	for (i = k = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		if (y >= l&&z >= l)
		{
			a[k].no = x;
			a[k].age = 1;
			a[k].de = y;
			a[k].cai = z;
			a[k].sum = y + z;
			k++;
			if (y >= h&&z >= h)
			{
				a[k-1].age = 4;//才德全尽
				continue;
			}
			if (y >= h)//德胜才
			{
				a[k-1].age = 3;
				continue;
			}
			if (y >= z)//才德兼亡但尚有德胜才
				a[k-1].age = 2;
		}
	}
	sort(a, a + k, cmp);
	cout << k << endl;
	for (i = 0; i < k; i++)
		cout << a[i].no << " " << a[i].de << " " << a[i].cai << endl;
	return 0;
}
