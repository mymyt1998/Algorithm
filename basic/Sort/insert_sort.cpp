void InsertionSort(vector<int> &arr)
{
	//最坏O(n^2)，最好O(n)，平均O(n^2)
	int n = arr.size();
	for (int i = 1; i < n; i++)         // 抓扑克牌排序
	{
		int get = arr[i];                 // 右手抓到一张扑克牌
		int j = i - 1;                  // 拿在左手上的牌总是排序好的
		while (j >= 0 && arr[j] > get)    // 将抓到的牌与手牌从右向左进行比较
		{
			arr[j + 1] = arr[j];            // 如果该手牌比抓到的牌大，就将其右移
			j--;
		}
		arr[j + 1] = get; // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边
		//相等元素的相对次序未变，所以插入排序是稳定的
	}
}
