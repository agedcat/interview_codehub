#include<iostream>
#include<vector>
using namespace std;

// int research_run(vector<int>&nums,int target,int left,int right)
// {
//     int mid=(left+right)/2;
//     if(target==nums[mid]) return mid;
//     if(left==right&&nums[left]!=target) return -1;
//     if(nums[left]<nums[mid])
//     {
//         if(nums[left]<=target&&target<=nums[mid])
//         {
//             return research_run(nums,target,left,mid-1);
//         }
//         else{
//             return research_run(nums,target,mid+1,right);
//         }
//     }
//     else{
//         if(nums[mid]<=target&&target<=nums[right])
//         {
//             return research_run(nums,target,mid+1,right);
//         }
//         else{
//             return research_run(nums,target,left,mid-1);
//         }
//     }
// }

int research_run(vector<int>&nums,int target,int left,int right)
{
    int mid=(left+right)/2;
    if(target==nums[mid]) return mid;
    if(left==right&&nums[left]!=target) return -1;
    if(nums[left]<nums[mid]&&nums[left]<=target&&target<=nums[mid])
    {
       return research_run(nums,target,left,mid-1);
    }
    else if(nums[left]>nums[mid]&&!(nums[mid]<=target&&target<=nums[right]))
    {
        return research_run(nums,target,left,mid-1);
    }
    else{
        return research_run(nums,target,mid+1,right);
    }
}


// int search(vector<int>&nums,int target)
// {
//     return research_run(nums,target,0,nums.size()-1);
    
// }

int search(vector<int>&nums,int target)
{
    int left=0;
    int right=nums.size()-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(target==nums[mid]) return mid;
        if(nums[left]<nums[mid]&&nums[left]<=target&&target<=nums[mid])
        {
            right=mid;
        }
        else if(nums[left]>nums[mid]&&!(nums[mid]<=target&&target<=nums[right]))
        {
            right=mid;
        }
        else{
            left=mid+1;
        }

    }
    return -1;

}



int main(void)
{
    vector<int>nums={4,5,6,7,0,1,2};
    int target=0;
    int res=-1;
    res=search(nums,target);
    cout<<res<<endl;
    return 0;
}