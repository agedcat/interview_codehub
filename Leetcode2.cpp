#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1,ListNode *l2)
{
    ListNode* head=new ListNode(0);
    ListNode *t=head;
    int add=0;
    while(l1||l2||add)
    {
        int l1val=l1?l1->val:0;
        int l2val=l2?l2->val:0;
        int sum=l1val+l2val+add;
        ListNode* temp=new ListNode(sum%10);
        add=sum/10;
        t->next=temp;
        t=temp;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;


    }
    return head->next;


}

int main()
{
    ListNode* t1=new ListNode(2);
    ListNode* t2=new ListNode(4);
    ListNode* t3=new ListNode(3);
    ListNode* p=t1;
    t1->next=t2;
    t2->next=t3;
    ListNode* t4=new ListNode(5);
    ListNode* t5=new ListNode(6);
    ListNode* t6=new ListNode(4);
    ListNode* q=t4;
    t4->next=t5;
    t5->next=t6;
    ListNode* ans=addTwoNumbers(p,q);
    while(ans)
    {
        cout<<ans->val<<endl;
        ans=ans->next;
    }
    system("pause");
    return 0;
}