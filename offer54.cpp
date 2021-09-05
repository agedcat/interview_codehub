#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res=INT32_MIN;
void DFS(TreeNode* root,int k,int& count)
{
    if(root==nullptr) return;
    DFS(root->right,k,count);
    count++;
    if(count==k) res = root->val;
    DFS(root->left,k,count);

}

int kthLargest(TreeNode* root, int k)
{
    if(root==nullptr) return 0;
    int count=0;
    DFS(root,k,count);
    return res;
}