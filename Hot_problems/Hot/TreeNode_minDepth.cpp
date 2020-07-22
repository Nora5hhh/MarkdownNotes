//lc_111，BFS求最小深度
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
int DminDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left||!root->right)
    {
        return max(minDepth(root->left),minDepth(root->right))+1;
    }
    else
    {
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
}

//BFS
int minDepth(TreeNode* root) {
    queue<TreeNode*> que;
    if(root)
    {
        que.push(root);
    }
    int minLen=0;
    while(!que.empty())
    {
        int len=que.size();
        ++minLen;
        for(int i=0;i<len;++i)
        {
            TreeNode* node=que.front();
            que.pop();
            if(node->left)
            {
                que.push(node->left);
            }
            if(node->right)
            {
                que.push(node->right);
            }
            if(!node->right&&!node->left)
            {
                return minLen;
            }
        }
    }
        return minLen;
}

int main()
{
	TreeNode* root = new TreeNode(3);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	root->left = new TreeNode(9);
	int len=minDepth(root);
    cout<<"the result is: "<<len<<endl;
	return 0;
}