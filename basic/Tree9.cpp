 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} };
    //把二叉搜索树转换为累加树
 class Solution {
 public:
	 TreeNode * convertBST(TreeNode* root) {
		 if (!root)
			 return root;
		 convertBST(root->right);
		 root->val = root->val + rightsum;
		 rightsum = root->val;
		 convertBST(root->left);
		 return root;
	 }
 private:
	 int rightsum = 0;
 };
