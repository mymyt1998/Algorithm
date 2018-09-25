//在空间复杂度为O(1)的条件下删除数组的重复元素
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) 
	{
		if (nums.size == 0)
			return 0;
		int endd = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[endd])
			{
				nums[++endd] = nums[i];
			}
		}
		return endd+1;
	}
};
int main()
{
	int i;
	vector<int> b = { 0,0,1,1,1,2,2,3,3,4 };
	Solution a;
	i=a.removeDuplicates(b);
	for (int j=0; j<i; j++)
		cout << b[j] << endl;
	cin >> i;
	return 0;
}
