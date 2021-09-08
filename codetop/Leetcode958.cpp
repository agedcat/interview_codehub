#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isCompleteTree(TreeNode* root)
{
    if(root==nullptr) return true;
    queue<TreeNode*>q;
    bool isNullptr=false;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* cur=q.front();
        q.pop();
        if(cur==nullptr)
        {
            isNullptr=true;
            continue;
        }
        else{
            if(isNullptr)
            {
                //在空节点后又出现非空结点
                return false;
            }
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return true;
}
