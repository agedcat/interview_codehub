#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* root,int &maxPath)
{
    if(!root) return 0;
    int left=dfs(root->left,maxPath);
    int right=dfs(root->right,maxPath);
    if(left+right>maxPath)
    {
        maxPath=left+right;
    }
    return max(left,right)+1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    if(!root) return 0;
    int maxPath=0;
    dfs(root,maxPath);
    return maxPath;
}