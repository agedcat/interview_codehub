/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        if(!root->left&&!root->right) return root;
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        TreeNode* temp=left;
        root->left=root->right;
        root->right=temp;
        return root;
    }
};
// @lc code=end

