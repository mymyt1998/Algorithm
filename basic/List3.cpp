 class SolutionMe {
 public:
	 ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		 ListNode* tmp = new ListNode(1);
		 ListNode* re = tmp;
		 int t = 0, c, x, y;
		 while (l1 != NULL || l2 != NULL)
		 {
			 x = (l1 == NULL) ? 0 : l1->val;
			 y = (l2 == NULL) ? 0 : l2->val;
			 c = x + y + t;
			 t = c > 9 ? 1 : 0;
			 c %= 10;
			 tmp->next = new ListNode(c);
			 tmp = tmp->next;
			 l1 = l1 ? l1->next : l1;
			 l2 = l2 ? l2->next : l2;
		 }
		 if (t)
			 tmp->next = new ListNode(1);
		 return re->next;
	 }
 };
 static int goushi = []()->int {
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 return 0;
 }();

 class SolutionOther {
 public:
	 using Node = ListNode * ;//using即typedef
	 Node add(Node sub1, Node sub2, int over) {
		 if (!sub2 && over == 0) 
			 return sub1;
		 if (!sub1)
			 sub1 = new ListNode(0);
		 int val = sub2 ? sub2->val : 0;
		 Node next = sub2 ? sub2->next : nullptr;//nullptr空指针类型
		 sub1->val += val + over;
		 over = sub1->val / 10;
		 sub1->val %= 10;
		 sub1->next = add(sub1->next, next, over);
		 return sub1;
	 }
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 return add(l1, l2, 0);
	 }
 };
