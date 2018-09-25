//子集和问题
//回溯法
#include <iostream>
using namespace std;
int s[1005], c, n;
bool P[1005] = { false };//标记走过否
bool dfs(int dep, int sum)//记录深度
{
	if (sum > c)//已经不能找到正确解，剪枝
		return false;
	if (sum == c)//找到解
	{
		for (int i = 0; i < n; i++)
			if (P[i])
				cout << s[i] << " ";
		cout << endl;
		return true;
	}
	if (dep == n)//已经搜索完
		return false;
	P[dep] = true;//加上第dep点
	if (dfs(dep + 1, sum + s[dep]))
		return true;

	P[dep] = false;//不加第dep点
	if (dfs(dep + 1, sum))
		return true;
	return false;
}

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	dfs(0, 0);
	return 0;
}