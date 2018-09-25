void binary_insert_sort(vector<int> &arr)//二分排序，扑克牌
{
	//稳定排序
	//最差O(n^2)，最优O(nlogn)，平均O(n^2)
	int i, len = arr.size(),p;
	//已经排好序的区间
	int _left ,_right,_mid;
	for (i = 1; i < len; i++)//待插入排序的元素
	{
		_left = 0;
		_right = i - 1;
		p = arr[i];
		while (_left <= _right)//二分法查找适当的插入位置
		{
			_mid = (_left + _right) / 2;
			if (p < arr[_mid])
				_right = _mid - 1;
			else
				_left = _mid + 1;
		}
		//arr.insert(arr.begin() + _left, arr[i]);
		//arr.erase(arr.begin() + i + 1);
		//将arr[i]放到合适的位置，删除原有的arr[i]
		for (int k = i; k > _left; k--)
		{
			arr[k] = arr[k - 1];
		}
		arr[_left] = p;
	}
}
