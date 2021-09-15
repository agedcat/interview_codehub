#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *virtualHead=new ListNode();
    virtualHead->next=head;

    ListNode* pre=virtualHead;
    ListNode* cur=head;
    ListNode* tail=head;

    while(n--)
    {
        tail=tail->next;
    }
    while(tail)
    {
        tail=tail->next;
        cur=cur->next;
        pre=pre->next;
    }

    pre->next=cur->next;
    return virtualHead->next;
}