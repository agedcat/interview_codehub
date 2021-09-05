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

ListNode* deleteDuplicates(ListNode* head)
{
    if(head==nullptr||head->next==nullptr) return head;

    ListNode* virtualHead=new ListNode(-1,head);
    ListNode* pre=virtualHead;
    ListNode* cur=pre->next;

    while(cur->next!=nullptr)
    {
        if(cur->next->val==cur->val)
        {
            pre->next=cur->next;
            cur=pre->next;
            continue;
        }
        cur=cur->next;
        pre=pre->next;
    }

    return virtualHead->next;
}