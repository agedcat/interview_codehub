#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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

void preOrderRecur(TreeNode* root,vector<int>&res)
{
    if(root==nullptr) return;
    res.push_back(root->val);
    preOrderRecur(root->left,res);
    preOrderRecur(root->right,res);
}

void inOrderRecur(TreeNode* root,vector<int>&res)
{
    if(root==nullptr) return;
    inOrderRecur(root->left,res);
    res.push_back(root->val);
    inOrderRecur(root->right,res);
}

void postOrderRecur(TreeNode* root,vector<int>&res)
{
    if(root==nullptr) return;
    postOrderRecur(root->left,res);
    postOrderRecur(root->right,res);
    res.push_back(root->val);
}

void preOrderIteration(TreeNode* root,vector<int>&res)
{
    if(root==nullptr) return ;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node=st.top();
        st.pop();
        res.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
}

void inOrderIteration(TreeNode* root,vector<int>&res)
{
    if(root==nullptr) return ;
    stack<TreeNode*>st;
    TreeNode* cur=root;
    while(cur!=nullptr||!st.empty())
    {
        if(cur!=nullptr)
        {
            st.push(cur);
            cur=cur->left;   //左
        }
        else{
            cur=st.top();
            st.pop();
            res.push_back(cur->val);//中
            cur=cur->right;//右
        }
    }  
}

void postOrderIteration(TreeNode* root,vector<int>&res)
{
    if(root==nullptr) return ;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node=st.top();
        st.pop();
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }   
    reverse(res.begin(),res.end());
}


void levelOrder(TreeNode* root,vector<vector<int>>&res)
{
    if(root==nullptr) return ;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            TreeNode* cur=q.front();
            q.pop();
            if(!cur) continue;
            level.push_back(cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }
        if(level.size()>0) res.push_back(level);
    }
}

void levelOrder_single(TreeNode* root,vector<int>&res)
{
    if(root==nullptr) return ;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* cur=q.front();
            q.pop();
            if(!cur) continue;
            res.push_back(cur->val);
            q.push(cur->left);
            q.push(cur->right);
        }
    }
}

void levelOrder_DFS(TreeNode* root,vector<vector<int>>&res,int level)
{
    if(root==nullptr) return ;
    if(level>=res.size()) res.push_back(vector<int>());
    res[level].push_back(root->val);
    levelOrder_DFS(root->left,res,level+1);
    levelOrder_DFS(root->right,res,level+1);
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>>res;
    levelOrder_DFS(root,res,0);
    return res;
}



    

