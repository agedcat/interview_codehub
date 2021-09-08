#include<iostream>
#include<list>

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* prev=nullptr;
    ListNode* curr=head;
    while(curr)
    {
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

ListNode* reverseList1(ListNode* head)
{
    if(!head||!head->next) return head;
    ListNode* newHead=reverseList1(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newHead;
}

