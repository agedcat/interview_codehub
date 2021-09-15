#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector<int> exchange(vector<int>& nums)
// {
//     bool existOdd=true;
//     for(int i=0;i<nums.size();++i)
//     {
//         if(nums[i]%2==1) continue;
//         int j=i+1;
//         for(;j<nums.size();++j)
//         {
//             if(nums[j]%2==1)
//             {
//                 swap(nums[i],nums[j]);
//                 break;
//             }
//         }
//         if(j==nums.size()) existOdd=false;
//         if(!existOdd) break;
//     }
//     return nums;
// }

// vector<int> exchange(vector<int>& nums)
// {
//     int len=nums.size();
//     int left=0;
//     int right=0;
//     while(left<len)
//     {
//         while(left<len&&nums[left]%2==1)
//         {
//             left++;
//         }
//         if(left>=len) break;
//         right=left+1;
//         while(right<len&&nums[right]%2==0)
//         {
//             right++;
//         }
//         if(right>=len) break;
//         swap(nums[left],nums[right]);
//         left++;
//         right++;
//     }
//     return nums;
// }
vector<int> exchange(vector<int>& nums)
{
    int len=nums.size();
    int left=0;
    int right=len-1;
    while(left<right)
    {
        if(nums[left]%2==1)
        {
            left++;
            continue;
        }
        if(nums[right]%2==0)
        {
            right--;
            continue;
        }
        swap(nums[left++],nums[right--]);

    }
    return nums;
}

int main(void)
{
    vector<int>nums={1,3,5};
    vector<int>ans=exchange(nums);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}