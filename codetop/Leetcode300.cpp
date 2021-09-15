#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>&nums)
{
    vector<int>dp(nums.size(),1);
    for(int i=0;i<nums.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            if(nums[i]>nums[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }            
        }
    }
    return *max_element(dp.begin(),dp.end());
}

int main(void)
{
    vector<int>nums={10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}