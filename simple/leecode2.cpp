//leetcode 买卖股票的最佳时机II
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
public:
	int maxProfit(vector<int>& prices)
	{
			int len = prices.size();
			if (len <= 1)
				return 0;
			int sum = 0;
			for (int i = 0; i < len-1; i++)
			{
				if (prices[i] < prices[i + 1])
					sum += prices[i + 1] - prices[i];
			}
			return sum;
	}
};
int main()
{
	int i;
	vector<int> b = { 7,1,5,3,6,4 };
	Solution a;
	i=a.maxProfit(b);
	cout << i << endl;
	cin >> i;
	return 0;
}
