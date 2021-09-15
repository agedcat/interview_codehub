#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// int firstMissingPositive(vector<int>& nums)
// {
//     if(nums.empty()) return -1;
//     unordered_map<int,bool>mp;

//     for(int i=0;i<nums.size();++i)
//     {
//         if(mp[nums[i]]) continue;
//         mp[nums[i]]=true;
//     }

//     for(int i=1;i<=nums.size();++i)
//     {
//         if(!mp[i]) return i;
//     }
//     return nums.size()+1;
// }

int firstMissingPositive(vector<int>& nums)
{
    if(nums.empty()) return -1;
    int len=nums.size();

    for(int i=0;i<len;++i)
    {
        while(nums[i]>0&&nums[i]<len&&nums[nums[i]-1]!=nums[i])
        {
            swap(nums[i],nums[nums[i]-1]);
        }
    }

    for(int i=0;i<len;++i)
    {
        if(nums[i]!=i+1) return i+1;
    }
    return len+1;
}

int main(void)
{
    vector<int>nums={3,4,-1,1};
    cout<<firstMissingPositive(nums)<<endl;
    return 0;
}