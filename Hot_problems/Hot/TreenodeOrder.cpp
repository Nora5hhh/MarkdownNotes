//lc_102，二叉树的顺序遍历，DFS或BFS解决
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//BFS
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	if (root == NULL) return res;
	queue<TreeNode*> que;
	que.push(root);
	while (!que.empty())
	{
		int len = que.size();
		res.push_back(vector<int>());
		for (int i = 0; i < len; ++i)
		{
			auto node = que.front();
			que.pop();
			res.back().push_back(node->val);
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return res;
}

void order(TreeNode* node,vector<vector<int>>& res,int level)
{
    if(!node)
    {
        return ;
    }
    if(res.size()==level)
    {
        res.push_back(vector<int>());
    } 
    res[level].push_back(node->val);
    if(node->left) order(node->left,res,level+1);
    if(node->right) order(node->right,res,level+1);
}

//DFS
vector<vector<int>> DlevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    order(root,res,0);
    return res;
}

TreeNode* createTreeNode(vector<int>& input, int cur, int len)
{
	if (cur == len/2||cur==len)
	{
		return nullptr;
	}
	TreeNode* croot = new TreeNode(input[cur]);
	croot->left = createTreeNode(input, cur + 1, len);
	croot->right = createTreeNode(input, len/2 + 1, len);
	return croot;
}

int main()
{
	vector<vector<int>> res;
	/*vector<int> input;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		input.push_back(x);
	}*/
	TreeNode* root = new TreeNode(3);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	root->left = new TreeNode(9);
	//TreeNode* node = createTreeNode(input, 0, input.size());
	res = levelOrder(root);
    res=DlevelOrder(root);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}