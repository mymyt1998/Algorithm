/*
catalan+大数乘除
Cn+1=Cn*(4n+2)/(n+2)
*/
#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ULL;
#define HM 100000000
ULL catalan[110][10];
void setCatalan()
{
	int i, j;
	memset(catalan, 0, sizeof(catalan));
	catalan[0][0] = 1;
	catalan[0][1] = 1;
	for (i = 1; i <= 100; i++) {
		//各个亿进制位做乘法 
		for (j = 1; j <= (int)catalan[i - 1][0]; j++)
			catalan[i][j] = (4*i+2) * catalan[i - 1][j];

		ULL r1 = 0, r2;
		// 各个亿进制位做除法
		for (j = (int)catalan[i - 1][0]; j >= 1; j--) {
			r2 = (r1 * HM + catalan[i][j]) % (i + 2);
			catalan[i][j] = (r1 * HM + catalan[i][j]) / (i + 2);
			r1 = r2;
		}

		// 进行亿进制调整 
		for (j = 1; j <= (int)catalan[i - 1][0]; j++) {
			catalan[i][j + 1] += catalan[i][j] / HM;
			catalan[i][j] %= HM;
		}

		catalan[i][0] = catalan[i][j] > 0 ? catalan[i - 1][0] + 1 : catalan[i - 1][0];
	}
}

int main(void)
{
	setCatalan();
	int n, i;
	while (cin>>n) 
	{
		n--;
		printf("%lld", catalan[n][catalan[n][0]]);
		for (i = (int)catalan[n][0] - 1; i >= 1; i--) {
			printf("%08lld", catalan[n][i]);
		}
		printf("\n");
	}
	return 0;
}
