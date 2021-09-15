#include<iostream>
#include<vector>
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


 
int DFS(TreeNode* root,int &maxSum)
{
    if(root==nullptr)
    {
        return 0;
    }
    int leftSum=max(DFS(root->left,maxSum),0);
    int rightSum=max(DFS(root->right,maxSum),0);
    int innerSum=root->val+leftSum+rightSum;
    maxSum=innerSum>maxSum?innerSum:maxSum;
    int outputSum=max(leftSum,rightSum)+root->val;
    return outputSum;  
} 

int maxPathSum(TreeNode* root) 
{
   int maxSum=INT32_MIN;
   DFS(root,maxSum);
   return maxSum;
}

    