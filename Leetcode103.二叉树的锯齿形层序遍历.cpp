/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    void levelOrder(TreeNode* root,vector<vector<int>>&res,int lev)
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
                TreeNode* node=q.front();
                q.pop();
                if(node==nullptr) continue;
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if(lev%2==1) reverse(level.begin(),level.end());
            lev++;
            if(level.size()>0) res.push_back(level);

        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        levelOrder(root,res,0);
        return res;


    }
};
// @lc code=end

