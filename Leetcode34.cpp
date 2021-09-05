#include<iostream>
#include<vector>
using namespace std;

// int binarySearch(vector<int>& nums,int target,int left,int right)
// {
//     int mid=(left+right)/2;
//     // if(left==right)
//     // {
//     //     if(nums[mid]==target)
//     //     {
//     //         return mid;
//     //     } 
//     //     else{
//     //         return -1;
//     //     }
//     // }
//     if(nums[mid]==target) return mid;
//     if(left>right) return -1;
//     if(nums[mid]<target)
//     {
//         return binarySearch(nums,target,mid+1,right);
//     }
//     else{
//         return binarySearch(nums,target,left,mid-1);
//     }
// }


int binarySearch(vector<int>& nums,int target,bool findLeft)
{
    int left=0;
    int right=nums.size()-1;
    int ans=nums.size();
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[mid]>target||(findLeft&&nums[mid]>=target))
        {
            right=mid-1;
            ans=mid;
        }
        else{
            left=mid+1;
        }

    }
    return ans;
} 


// vector<int> searchRange(vector<int>& nums, int target)
// {
//     if(nums.empty()) return {-1,-1};
//     int index=binarySearch(nums,target,0,nums.size()-1);
//     if(index==-1) return {-1,-1};
//     int left=index;
//     int right=index;

//     while((right+1<nums.size())&&(nums[right]==nums[right+1]))
//     {
//         right++;
//     }

//     while((left>0)&&(nums[left]==nums[left-1]))
//     {
//         left--;
//     }
//     return {left,right};
// }

vector<int> searchRange(vector<int>& nums, int target)
{
    if(nums.empty()) return {-1,-1};
    int left=binarySearch(nums,target,true);
    int right=binarySearch(nums,target,false)-1;
    cout<<left<<" "<<right<<endl;
    if(left<nums.size()&&right<nums.size()&&nums[left]==nums[right]) return {left,right};
    return {-1,-1};
    
}

int main(void)
{
    vector<int>nums={1};
    int target=0;
    vector<int>ans=searchRange(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}


