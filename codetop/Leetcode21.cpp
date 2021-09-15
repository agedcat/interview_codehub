#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
    ListNode* hair=new ListNode(-1);

    ListNode* pre=hair;
    while(l1!=nullptr && l2 != nullptr)
    {
        if(l1->val<l2->val)
        {
            pre->next=l1;
            l1=l1->next;
        }
        else{
            pre->next=l2;
            l2=l2->next;
        }
        pre=pre->next;
    }

    pre->next=(l1==nullptr?l2:l1);

    return hair->next;
}

ListNode* mergeTwoLists_r(ListNode* l1,ListNode* l2)
{
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1;

    if(l1->val<l2->val)
    {
        l1->next=mergeTwoLists_r(l1->next,l2);
        return l1;
    }
    else{
        l2->next=mergeTwoLists_r(l1,l2->next);
        return l2;
    }
}