struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode * addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode ans(0), *p = &ans;//构造一个初始为0的链表
		int tmp = 0;
		while (l1 || l2 || tmp)
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + tmp;
			tmp = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return ans.next;
	};
