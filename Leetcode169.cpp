#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums)
{
    int ret=0;
    int flagNum;
    for(int i=0;i<nums.size();++i)
    {
        if(ret==0)
        {
            flagNum=nums[i];
        }
        if(nums[i]!=flagNum)
        {
            ret--;
        }
        else{
            ret++;
        }
    }
    return flagNum;
}

int main(void)
{
    vector<int>nums={2,2,1,1,1,2,2};
    int ans=majorityElement(nums);
    cout<<ans<<endl;
    return 0;
}