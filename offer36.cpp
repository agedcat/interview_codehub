#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node* treeToDoublyList(Node* root)
{
    if(root==nullptr) return root;
    Node* left=nullptr;
    Node* right=nullptr;
    if(root->left) left=treeToDoublyList(root->left);
    if(root->right) right=treeToDoublyList(root->right);
    Node* head=nullptr;
    if(left==nullptr&&right==nullptr) 
    {
        root->right=root;
        root->left=root;
        head = root;
    }
    if(left==nullptr&&right!=nullptr)
    {
        root->right=right;
        right->left->right=root;
        root->left=right->left;
        right->left=root;
        head = root;
    }
    if(left!=nullptr&&right==nullptr)
    {
        root->left=left->left;
        left->left=root;
        root->left->right=root;
        root->right=left;
        head = left;
    }
    if(left!=nullptr&&right!=nullptr)
    {
        root->left=left->left;
        root->right=right;
        left->left->right=root;
        left->left=right->left;
        left->left->right=left;
        right->left=root;
        head=left;
    }
    return head;
}