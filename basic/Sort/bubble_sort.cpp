void bubble_sort(vector<int> &arr) {
	//冒泡排序是稳定排序
	//空间复杂度为O(1)
	//平均时间复杂度为O(n^2)
	int i, j, change = 1,len=arr.size();
	for (i = 0; i < len - 1 && change != 0; i++)
	{
		change = 0;
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				change = 1;//确定该轮有发生交换，没有则已排序
				//最好情况下的时间复杂度为O(n)
			}
		//最坏情况下的时间复杂度为O(n^2)
	}
}
