#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root)
{
    if(root==nullptr) return 0;
    if(root->left==nullptr&&root->right==nullptr) return 1;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return max(left,right)+1;
}


bool isBalanced(TreeNode* root) 
{
    if(root==nullptr) return true;
    if(root->left==nullptr&&root->right==nullptr) return true;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    if(abs(left-right)<=1){
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    else{
        return false;
    }
    

}