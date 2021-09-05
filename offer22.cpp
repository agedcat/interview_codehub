#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k)
{
    if(head==nullptr) return head;
    ListNode* pre=head;
    ListNode* cur=head;
    while(k--)
    {
        cur=cur->next;
    }
    while(cur!=nullptr)
    {
        cur=cur->next;
        pre=pre->next;
    }
    return pre;
}