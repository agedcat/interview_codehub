#include<iostream>
#include<vector>
using namespace std;

int searchBin(vector<int>&nums,int target,int left,int right)
{
    int mid=(left+right)/2;
    if(left>right) return -1;
    if(nums[mid]==target) 
    {
        return mid;
    }
    else if(nums[mid]<target)
    {
        return searchBin(nums,target,mid+1,right);
    }
    else{
        return searchBin(nums,target,left,mid-1);
    }
}

int search(vector<int>&nums,int target)
{
    return searchBin(nums,target,0,nums.size()-1);
}

int main(void)
{
    vector<int>nums={-1,0,3,5,9,12};
    int target=2;
    int ans=search(nums,target);
    cout<<ans<<endl;
}