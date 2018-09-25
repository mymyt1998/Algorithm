#include<iostream>
#include<algorithm>
using namespace std;
struct cy {
	int x, num;
}a[2500001];
bool cmp(const cy &a, const cy &b)
{
	return a.x > b.x;
}
int main()
{
	int i, j, v, n, sum, q;
	double mid;
	while (cin >> n, n >= 0)
	{
		v = q = sum = 0;
		for (i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].num;
			sum += a[i].x * a[i].num;
		}
		mid = sum *1.0 / 2;
		sort(a, a + n, cmp);
		for (i = 0; i < n; i++)
		{
			for (j = a[i].num; j > 0; j--)
				if ((v + a[i].x) <= mid)
					v += a[i].x;
			if (v > mid)
				break;
		}
		cout << sum - v << " " << v << endl;
	}
	return 0;
}
