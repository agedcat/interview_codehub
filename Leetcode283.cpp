#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// void moveZeroes(vector<int>& nums)
// {
//     for(int i=0;i<nums.size();++i)
//     {
//         if(nums[i]!=0) continue;
//         int j=i+1;
//         for(;j<nums.size();++j)
//         {
//             if(nums[j]==0) continue;
//             swap(nums[i],nums[j]);
//             break;
//         }
//         if(j==nums.size()) break;
//     }
// }

void moveZeroes(vector<int>& nums)
{
    int len=nums.size();
    int index=0;
    for(auto num : nums)
    {
        if(num!=0)
        {
            nums[index++]=num;
        }
    }
    for(int i=index;i<len;++i)
    {
        nums[i]=0;
    }
}

int main(void)
{
    vector<int>nums={0,0,1};
    moveZeroes(nums);
    for(auto e:nums)
    {
        cout<<e<<" ";
    }
    return 0;
}