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

bool isExist=false;

void findAnswer(TreeNode* root,int targetSum,int pathSum)
{
    if(root==nullptr)
    {
        if(root==nullptr&&pathSum==targetSum)
        {
            isExist=true;
        }
        return;
    }
    pathSum+=root->val;
    findAnswer(root->left,targetSum,pathSum);
    findAnswer(root->right,targetSum,pathSum);
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    if(root==nullptr) return false;
    findAnswer(root,targetSum,0);
    return isExist;
}

int main(void)
{
    TreeNode* root=nullptr;
    bool flag=hasPathSum(root,0);
    cout<<flag<<endl;
    return 0;
}