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
class Solution {//N叉树的层序遍历
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> re;
		if (!root)
			return re;
		queue<Node*> nod;
		Node* R;
		nod.push(root);
		while (!nod.empty())
		{
			vector<int> cur;
			int len = nod.size();//当前层的结点个数
			for (int i = 0; i < len; i++)
			{
				R = nod.front();
				nod.pop();
				cur.push_back(R->val);//存当前层节点
				for (auto it : R->children)//放入下一层所有子节点
					nod.push(it);
			}
			re.push_back(cur);
		}
		return re;
	} 
};
