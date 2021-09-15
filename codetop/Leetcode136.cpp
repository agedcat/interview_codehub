#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums)
{
    int ans=nums[0];
    for(int i=1;i<nums.size();++i)
    {
        ans^=nums[i];
    }
    return ans;
}

int main(void)
{
    vector<int>nums={2,2,1};
    cout<<singleNumber(nums)<<endl;
    return 0;
}