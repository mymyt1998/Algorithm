//PAT找出镇上最年长和最年轻的人
//字符串的运用
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);//取消cin同步
	int n; 
	while (cin >> n)
	{
		string name, str;
		string minStr = "z", Min = "";
		string maxStr = "", Max = "";
		string start = "1814/09/06";//最年老
		string end = "2014/09/06";//最年轻
		int ans = 0;
		while(n--)
		{
			cin >> name >> str;
			if (str >= start && str <= end)//字符串自动转化为数字比较大小
			{
				ans++;
				if (minStr > str)
				{
					minStr = str;
					Min = name;
				}
				if (maxStr < str)
				{
					maxStr = str;
					Max = name;
				}
			}
		}
		cout << ans << " " << Min << " " << Max << endl;
	}
	return 0;
}
