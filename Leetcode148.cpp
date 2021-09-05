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

ListNode* mergerTwoList(ListNode* firstHead,ListNode* secondHead)
{
    //合并两个有序链表
    if(!firstHead) return secondHead;
    if(!secondHead) return firstHead;

    ListNode* virtualHead=new ListNode(0);
    ListNode* firstPtr=firstHead;
    ListNode* secondPtr=secondHead;
    ListNode* curPtr=virtualHead;
    while(firstPtr&&secondPtr)
    {
        if(firstPtr->val<secondPtr->val)
        {
            curPtr->next=firstPtr;
            firstPtr=firstPtr->next;
            curPtr=curPtr->next;
            curPtr->next=nullptr;
        }
        else{
            curPtr->next=secondPtr;
            secondPtr=secondPtr->next;
            curPtr=curPtr->next;
            curPtr->next=nullptr;
        }
    }
    if(firstPtr) curPtr->next=firstPtr;
    if(secondPtr) curPtr->next=secondPtr;
    return virtualHead->next;
}

ListNode* findMidPtr(ListNode* head)
{
    //获取中间结点
    if(head==nullptr||head->next==nullptr) return head;

    ListNode* fastPtr=head->next->next;
    ListNode* slowPtr=head;
    if(fastPtr&&fastPtr->next)
    {
        fastPtr=fastPtr->next->next;
        slowPtr=slowPtr->next;
    }

    return slowPtr;
}

int getLength(ListNode* head)
{
    //获得链表长度
    int length=0;
    while(head!=nullptr)
    {
        length++;
        head=head->next;
    }
    return length;
}

ListNode* split(ListNode* head,int step)
{
    //断链，返回第二部分链表的头结点
    if(head==nullptr) return head;
    ListNode* cur=head;
    for(int i=1;i<step&&cur->next!=nullptr;++i)
    {
        cur=cur->next;
    }
    ListNode* right=cur->next;
    cur->next=nullptr;
    return right;
}

ListNode* sortList(ListNode* head)
{
    if(head==nullptr||head->next==nullptr) return head;
    int length=getLength(head);

    ListNode* virtualHead=new ListNode(-1,head);
    //步长从1，2，4，...，一直到length
    for(int subLength=1;subLength<length;subLength*=2)
    {
        //pre指针指向已经排好序的链表末尾，cur指针指向将要进行处理的链表的头结点
        ListNode* pre=virtualHead;
        ListNode* cur=virtualHead->next;

        //while循环处理一次步长的所有合并操作
        while(cur!=nullptr)
        {
            //head1为第一部分头
            ListNode* head1=cur;
            //head2为第二部分头
            ListNode* head2=split(head1,subLength);
            //cur为剩余需要处理的链表的头
            cur=split(head2,subLength);
            //合并一二部分
            ListNode* merged=mergerTwoList(head1,head2);
            //更新其他指针的状态
            pre->next=merged;
            while(pre->next!=nullptr)
            {
                pre=pre->next;
            }
        }
    }
    return virtualHead->next;
}

// ListNode* sortList(ListNode* head)
// {
//     if(head==nullptr||head->next==nullptr) return head;

//     ListNode* midPtr=findMidPtr(head);
//     ListNode* rightHead=midPtr->next;
//     midPtr->next=nullptr;
//     ListNode* leftPtr=sortList(head);
//     ListNode* rightPtr=sortList(rightHead);
//     return mergerTwoList(leftPtr,rightPtr);
// }