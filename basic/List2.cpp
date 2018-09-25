 class Solution {
 public:
	 ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		 //合并有序数列
		 if (l1 == NULL) 
			 return l2;
		 if (l2 == NULL) 
			 return l1;
		 ListNode * re;
		 //取链表头指针
		 if (l1->val <= l2->val) {
			 re = l1;
			 l1 = l1->next;
		 }
		 else {
			 re = l2;
			 l2 = l2->next;
		 }
		 ListNode *p = re;
		 while (l1 != NULL && l2 != NULL)
		 {
			 if (l1->val <= l2->val)
			 {
				 p->next = l1;
				 l1 = l1->next;
			 }
			 else
			 {
				 p->next = l2;
				 l2 = l2->next;
			 }
			 p = p->next;
		 }
		//后面的直接插到末尾
		 if (l1 != NULL)
			 p->next = l1;
		 else 
			 p->next = l2;
		 return re;
	 }
 };
