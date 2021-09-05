#include<iostream>
#include<vector>
using namespace std;

int getMin(vector<int>& nums,int left,int right)
{
    if(left==right) return nums[left];
    int mid=(left+right)/2;
    if(nums[mid]>nums[right])
    {
        return getMin(nums,mid+1,right);
    }
    else{
        return getMin(nums,left,mid);
    }
}

int findMin(vector<int>& nums)
{
    int left=0;
    int right=nums.size()-1;
    return getMin(nums,left,right);
}

int main(void)
{
    vector<int>nums={4,5,6,7,0,1,2};
    cout<<findMin(nums)<<endl;
    return 0;
}