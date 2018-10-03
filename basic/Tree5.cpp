/*
二叉查找树（Binary Search Tree）（二叉排序树）
一棵空树，或者是具有下列性质的二叉树：
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 
它的左、右子树也分别为二叉排序树。*/
class Solution {//修剪二叉搜索树
public:
	TreeNode * trimBST(TreeNode* root, int L, int R) {
		if (!root)
			return NULL;
		if (root->val < L)
			return trimBST(root->right, L, R);
		if (root->val > R)
			return trimBST(root->left, L, R);
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
};
