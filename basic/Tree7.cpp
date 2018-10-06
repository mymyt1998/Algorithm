class Solution1 {//二叉树的所有路径
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ans;
		if (!root)
			return ans;
		Func(root, ans, to_string(root->val));
		return ans;
	}
	void Func(TreeNode* root, vector<string> &re, string cur)
	{
		if (!root->right && !root->left)
		{
			re.push_back(cur);
			return;
		}
		if (root->right)
		{
			Func(root->right, re, cur + "->" + to_string(root->right->val));
		}
		if (root->left)
		{
			Func(root->left, re, cur + "->" + to_string(root->left->val));
		}
	}
};
class Solution {//叶子相似的树
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> l1, l2;
		Leaf(l1,root1);//存两棵树的叶子结点
		Leaf(l2,root2);
		if (l1 == l2)
			return true;
		return false;
	}
	void Leaf(vector<int> &l, TreeNode* root)
	{
		if (root)
		{
			if (!root->left&&!root->right)
				l.push_back(root->val);
			Leaf(l, root->left);
			Leaf(l, root->right);
		}
	}
};
