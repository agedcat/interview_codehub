#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head){
    if(!head || !head->next){
        return head;
    }

    ListNode* virtualHead = new ListNode();
    virtualHead->next = head;
    ListNode* preNode = virtualHead;
    ListNode* curNode = head;
    while (curNode && curNode->next)
    {
        ListNode* nextNode = curNode->next->next;
        preNode->next = curNode->next;
        curNode->next->next = curNode;
        curNode->next = nextNode;

        preNode = curNode;
        curNode = nextNode;
    }
    
    return virtualHead->next;
}

