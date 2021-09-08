#include<iostream>
#include<queue>
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

bool check1(TreeNode* p,TreeNode* q)
{
    if(p==nullptr&&q==nullptr) return true;
    if((p==nullptr&&q!=nullptr)||(p!=nullptr&&q==nullptr))
    {
        return false;
    }
    if((p->val == q->val )&& check1(p->left,q->right) && (check1(p->right,q->left)))
    {
        return true;
    }
    return false;
}

bool check2(TreeNode* p,TreeNode* q)
{
    queue<TreeNode*>qu;
    qu.push(p);
    qu.push(q);
    while(!qu.empty())
    {
        p=qu.front();
        qu.pop();
        q=qu.front();
        qu.pop();

        if(p==nullptr && q==nullptr) continue;
        if(p==nullptr||q==nullptr) return false;
        if(p->val!=q->val) return false;

        qu.push(p->left);
        qu.push(q->right);

        qu.push(p->right);
        qu.push(q->left);
    }
    return true;
    
}

bool isSymmetric(TreeNode* root)
{
    return check1(root,root);
}