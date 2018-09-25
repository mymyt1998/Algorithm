void selection_sort(vector<int> &arr)
{
	//选择排序不稳定
	//时间复杂度O(n^2)
	int i, j, len = arr.size(),p_Min;
	for (i = 0; i < len-1; i++)//已排序的个数
	{
		p_Min = i;//记录区间最小值位置
		for (j = i; j < len; j++)
		{
			if (arr[j] <arr[p_Min])
			{
				p_Min = j;
			}
		}
		swap(arr[p_Min], arr[i]);
	}
}
