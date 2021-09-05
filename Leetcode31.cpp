#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    if(nums.empty()||nums.size()==1) return;
    int index=nums.size()-2;
    for(;index>=0;--index)
    {
        if(nums[index]<nums[index+1]) break;
    }
    cout<<index<<endl;
    if(index>=0)
    {
        int k=nums.size()-1;
        for(;k>=0;--k)
        {
            if(nums[index]<nums[k]) break;
        }
        cout<<k<<endl;
        swap(nums[index],nums[k]);
        reverse(nums.begin()+index+1,nums.end());
        return;

    }
    reverse(nums.begin(),nums.end());
}

int main(void)
{
    vector<int>nums={3,2,1};
    nextPermutation(nums);
    for(int i=0;i<nums.size();++i)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}
