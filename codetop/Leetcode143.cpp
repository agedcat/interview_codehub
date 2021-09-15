#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* findMidPos(ListNode* head)
{
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* pre=head;
    ListNode* cur=head;
    while(cur!=nullptr)
    {
        cur=cur->next;
        if(cur) cur=cur->next;
        pre=pre->next;
    }
    return pre;
}

ListNode* reverseList(ListNode* head)
{
    if(head==nullptr||head->next==nullptr) return head;
    ListNode* newHead=reverseList(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newHead;
}

void reorderList(ListNode* head)
{
    ListNode* midPointer=findMidPos(head);
    ListNode* newHead=reverseList(midPointer);
    ListNode* cur=head;
    while(newHead)
    {
        ListNode* nextPointer=newHead->next;
        newHead->next=cur->next;
        cur->next=newHead;
        newHead=nextPointer;
        cur=cur->next->next;
    }
    cur->next=nullptr;
}