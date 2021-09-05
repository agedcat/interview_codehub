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
    ListNode* virtualHead=new ListNode(-101,head);
    ListNode* prePtr=virtualHead;
    ListNode* curPtr=head;

    while(curPtr&&curPtr->next)
    {
        if(curPtr->val==curPtr->next->val)
        {
            while(curPtr&&curPtr->next&&curPtr->val==curPtr->next->val)
            {
                prePtr->next=curPtr->next;
                curPtr=prePtr->next;
            }
            prePtr->next=curPtr->next;
            curPtr=prePtr->next;
        }
        else{
            prePtr=prePtr->next;
            curPtr=curPtr->next;
        }
    }

    return virtualHead->next;
}