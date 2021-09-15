#include<iostream>
#include<vector>
#include<algorithm>

double findMedianSortedArrays(std::vector<int>& num1, std::vector<int>& num2)
{
    int m = num1.size();
    int n = num2.size();
    bool flag = false;
    bool flagLefti=false, flagLeftj=false, flagRighti=false, flagRightj=false;
    int mid=(m+n)/2;
    if((m+n) % 2 == 0) 
    {
        flag = true;
        mid-=1;
    }
    int lefti=0,leftj=0;
    int righti=m-1,rightj=n-1;
    int left=0,right=0;
    int countLeft=0,countRight=0;
    if(m==0)
    {
        if(flag==false) return (double)num2[mid];
        if(flag==true) return (num2[mid]+num2[mid+1])/2.0;
    } 
    if(n==0)
    {
        if(flag==false) return (double)num1[mid];
        if(flag==true) return (num1[mid]+num1[mid+1])/2.0;
    } 
    while(lefti<m&&leftj<n)
    {
        if(mid==0) 
        {
            left=num1[0]>num2[0]?num2[0]:num1[0];
            break;
        }
        if(num1[lefti]>num2[leftj])
        {
            leftj++;
            countLeft++;
            if(leftj>=n) flagLeftj=true;
        }
        else
        {
            lefti++;
            countLeft++;
            if(lefti>=m) flagLefti=true;
        }
        if(countLeft==mid&&!flagLefti&&!flagLeftj) 
        {
            left=num1[lefti]>num2[leftj]?num2[leftj]:num1[lefti];
            break;
        }
    }
    if(flagLefti)
    {
        left=num2[leftj+mid-countLeft];
    }
    if(flagLeftj)
    {
        left=num1[lefti+mid-countLeft];
    }
    while(righti>=0&&rightj>=0)
    {
        if(mid==0)
        {
            right=num1[0]>num2[0]?num1[0]:num2[0];
            break;
        }
        if(num1[righti]>num2[rightj])
        {
            righti--;
            countRight++;
            if(righti<0) flagRighti=true;
        }
        else
        {
            rightj--;
            countRight++;
            if(rightj<0) flagRightj=true;
        }
        if(countRight==mid&&!flagRighti&&!flagRightj) 
        {
            right=num1[righti]>num2[rightj]?num1[righti]:num2[rightj];
            break;
        }
    }
    if(flagRighti)
    {
        right=num2[rightj-mid+countRight];
    }
    if(flagRightj)
    {
        right=num1[righti-mid+countRight];
    }
    return (left+right)/2.0;
    
}

int getKthElement(std::vector<int>& num1,std::vector<int>&num2,int k)
{
    int m=num1.size();
    int n=num2.size();
    int index1=0,index2=0;

    while(true)
    {
        if(index1==m) return num2[index2+k-1];
        if(index2==n) return num1[index1+k-1];
        if(k==1) return std::min(num1[index1],num2[index2]);

        int newIndex1=std::min(index1+k/2-1,m-1);
        int newIndex2=std::min(index2+k/2-1,n-1);
        int pivot1=num1[newIndex1];
        int pivot2=num2[newIndex2];
        if(pivot1<=pivot2)
        {
            k -= newIndex1-index1+1;
            index1=newIndex1+1;
        }
        else{
            k -= newIndex2-index2+1;
            index2=newIndex2+1;
        }


    }
}

double findMedianSortedArrays1(std::vector<int>& num1, std::vector<int>& num2)
{
    int m=num1.size();
    int n=num2.size();
    int length=m+n;
    if(length%2==1) return (double)getKthElement(num1,num2,(length+1)/2);
    else{
        return (double)(getKthElement(num1,num2,length/2)+getKthElement(num1,num2,length/2+1))/2;
    }
}

int main(void)
{
    std::vector<int>num1={1,2};
    std::vector<int>num2={3,4};
    double ans=findMedianSortedArrays1(num1,num2);
    std::cout<<ans<<std::endl;
    system("pause");
    return 0;

}