#include<iostream>
#include<vector>

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

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    ListNode* ans=nullptr;
    for(int i=0;i<lists.size();i++)
    {
        ans=mergeTwoLists(ans,lists[i]);
    }
    return ans;
}

ListNode* merge(std::vector<ListNode*>& lists,int left,int right)
{
    if(left==right) return lists[left];
    if(left>right) return nullptr;

    int mid=(left+right)/2;
    return mergeTwoLists(merge(lists,left,mid),merge(lists,mid+1,right));

}

ListNode* mergeKLists_div(std::vector<ListNode*>& lists)
{
    return merge(lists,0,lists.size()-1);
}