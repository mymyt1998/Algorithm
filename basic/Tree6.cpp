class Solution {//N叉树的层序遍历
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> re;
		if (!root)
			return re;
		queue<Node*> nod;
		Node* R;
		nod.push(root);
		while (!nod.empty())//按每层遍历完所有结点，存入时按个数放
		{
			vector<int> cur;
			int len = nod.size();//当前层的结点个数
			for (int i = 0; i < len; i++)
			{
				R = nod.front();
				nod.pop();
				cur.push_back(R->val);
				for (auto it : R->children)
					nod.push(it);
			}
			re.push_back(cur);
		}
		return re;
	} 
};
