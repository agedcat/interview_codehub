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

vector<vector<int>>path;

void dfs(TreeNode* root,int targetSum,vector<int>tempPath,int pathSum)
{
    if(root==nullptr)
    {
        return;
    }
    pathSum+=root->val;
    tempPath.push_back(root->val);
    if(!root->left&&!root->right)
    {
        if(pathSum==targetSum)
        {
            path.push_back(tempPath);
        }
    }
    dfs(root->left,targetSum,tempPath,pathSum);
    dfs(root->right,targetSum,tempPath,pathSum);

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    if(!root) return {};
    vector<int>tempPath;
    dfs(root,targetSum,tempPath,0);
    return path;
}

