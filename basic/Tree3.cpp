class Node {//N叉树
public:
	int val;
	vector<Node*> children;
	Node() {}
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
class Solution1 {//递归法
public:
	vector<int> preorder(Node* root) {
		if (root != nullptr)
		{
			res.push_back(root->val);
			for (auto n : root->children)
				preorder(n);
		}
		return res;
	}
private:
	vector<int> res;
};
class Solution2 {//迭代法
public:
	vector<int> preorder(Node* root) {
		vector<int> ret;
		if (!root)
			return ret;
		stack<Node*> nod;//保存未被访问的结点
		nod.push(root);
		while (!nod.empty())
		{
			Node* R = nod.top();
			nod.pop();
			ret.push_back(R->val);
			for (auto it = R->children.crbegin(); it != R->children.crend(); ++it)
			{//反向遍历子节点
				nod.push(*it);
			}
		}
		return ret;
	}
};
