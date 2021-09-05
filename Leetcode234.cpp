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

bool isPalindrome(ListNode* head)
{
    if(!head||!head->next) return true;
    ListNode* midPointer=findMidPos(head);
    ListNode* newHead=reverseList(midPointer);
    ListNode* first=head;
    ListNode* second=newHead;
    while(first&&second)
    {
        if(first->val!=second->val)
        {
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;

}