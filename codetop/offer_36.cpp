#include<iostream>
#include<vector>
#include<algorithm>
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

Node *pre,*head;
void treeToDoublyList_run(Node* cur)
{
    if(cur==nullptr) return;
    treeToDoublyList_run(cur->left);
    if(pre==nullptr) 
    {
        head=cur;
    }
    else{
        pre->right=cur;
    }
    cur->left=pre;
    pre=cur;
    treeToDoublyList_run(cur->right); 
}

Node* treeToDoublyList(Node* root)
{
    if(root==nullptr) return nullptr;
    treeToDoublyList_run(root);
    head->left=pre;
    pre->right=head;
    return head;
}