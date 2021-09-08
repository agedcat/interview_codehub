#include<iostream>
#include<vector>
using namespace std;

int searchBin(int left,int right,int target)
{
    if(left>=right) return right;
    int mid=(left+right)/2;
    if((long long)mid*mid==target) 
    {
        return mid;
    }
    else if(right-left==1)
    {
        if((long long)right*right==target) 
        {
            return right;
        }
        else{
            return left;
        }
    }
    else if((long long)mid*mid<target)
    {
        return searchBin(mid,right,target);
    }
    else{
        return searchBin(left,mid,target);
    }
}

int mySqrt(int x)
{
    return searchBin(0,x/2+1,x);
}

int main(void)
{
    int x=0;
    int ans=mySqrt(x);
    cout<<ans<<endl;

}