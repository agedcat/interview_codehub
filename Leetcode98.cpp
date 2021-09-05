#include<iostream>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBST(TreeNode* root,long long left,long long right)
{
    if(!root) return true;
    if(root->val>=right || root->val<=left)
    {
        return false;
    }
    return isBST(root->left,left,root->val)&&isBST(root->right,root->val,right);
}

long long pre=LONG_MIN;

bool isBST1(TreeNode* root)
{
    if(!root) return true;
    bool left=isBST1(root->left);
    if(root->val<=pre)
    {
        return false;
    }
    pre=root->val;
    bool right=isBST1(root->right);
    return left&&right;
}

bool isValidBST(TreeNode* root)
{
    //return isBST(root,LONG_MIN,LONG_MAX);
    return isBST1(root);
}