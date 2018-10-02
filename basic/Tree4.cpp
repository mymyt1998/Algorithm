class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> ret;
		if (!root)
			return ret;
		stack<Node*> nod;
		nod.push(root);
		Node* R;
		while (!nod.empty())
		{
			R = nod.top();
			nod.pop();
			ret.push_back(R->val);
			for (auto it : R->children)
				nod.push(it);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
