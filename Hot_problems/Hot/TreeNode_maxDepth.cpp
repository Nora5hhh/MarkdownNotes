//lc_104，BFS、DFS求最大深度
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

//DFS
int DmaxDepth(TreeNode* root) {
  if(!root) return 0;
  return max(maxDepth(root->left),maxDepth(root->right))+1;
}

//BFS
int maxDepth(TreeNode* root) {
    int maxLen=0;
    queue<TreeNode*> que;
    if(root) que.push(root);
    while(!que.empty()) { 
        int len=que.size();
        ++maxLen;
        for(int i=0;i<len;++i) {
            TreeNode* node=que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return maxLen;
}

int main()
{
	TreeNode* root = new TreeNode(3);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	root->left = new TreeNode(9);
	int len=maxDepth(root);
    cout<<"the result is: "<<len<<endl;
	return 0;
}