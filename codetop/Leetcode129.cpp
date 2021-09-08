#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getSum(TreeNode* root,int& ans,int pathSum)
{
    if(root==nullptr)
    {
        return;
    }
    pathSum=pathSum*10+root->val;
    if(root->left==nullptr&&root->right==nullptr)
    {
        ans+=pathSum;
    }
    getSum(root->left,ans,pathSum);
    getSum(root->right,ans,pathSum);
}

int sumNumbers(TreeNode* root)
{
    int ans=0;
    getSum(root,ans,0);
    return ans;
}