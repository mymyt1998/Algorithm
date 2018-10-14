 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} };
 //判断两颗二叉树是否相同
 class Solution {
 public:
	 bool isSameTree(TreeNode* p, TreeNode* q) {
		 if (!p && !q)
			 return true;
		 if (!p||!q)
			 return false;
		 queue<TreeNode*> que1,que2;
		 TreeNode* cur1;
		 TreeNode* cur2;
		 que1.push(p);
		 que2.push(q);
	
		 while (!que1.empty())
		 {
			 cur1 = que1.front();
			 que1.pop();
			 cur2 = que2.front();
			 que2.pop();
			 if (cur1->val != cur2->val)
				 return false;
			 if (cur1->left)
			 {
				 if (cur2->left)
				 {
					 que1.push(cur1->left);
					 que2.push(cur2->left);
				 }
				 else
					 return false;
			 }
			 else if (cur2->left)
				 return false;
			 if (cur1->right)
			 {
				 if (cur2->right)
				 {
					 que1.push(cur1->right);
					 que2.push(cur2->right);
				 }
				 else
					 return false;
			 }
			 else if (cur2->right)
				 return false;
		 }
		 return true;
	 }
 };
