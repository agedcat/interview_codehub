#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int,int>index;

TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder,int preorder_left,int preorder_right,int inorder_left,int inorder_right)
{
    //递归出口
    if(preorder_left>preorder_right) return nullptr;
    //前序遍历的左端点就是根节点，找出根节点的值
    int preorder_root=preorder[preorder_left];
    //运用map来加速找到根节点在中序遍历中的下标
    int inorder_root_index=index[preorder_root];
    //算出左子树的结点个数
    int size_left_subtree=inorder_root_index-inorder_left;
    //创建根节点
    TreeNode* root=new TreeNode(preorder_root);

    //递归创建左右结点
    root->left=myBuildTree(preorder,inorder,preorder_left+1,preorder_left+size_left_subtree,inorder_left,inorder_root_index-1);
    root->right=myBuildTree(preorder,inorder,preorder_left+size_left_subtree+1,preorder_right,inorder_root_index+1,inorder_right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    for(int i=0;i<inorder.size();++i)
    {
        index[inorder[i]]=i;
    }
    return myBuildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
}