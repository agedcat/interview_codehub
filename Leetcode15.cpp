#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) 
{
    if(nums.empty()||nums.size()<3) return {};
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<=nums.size()-3;i++)
    {
        if(nums[i]>0) return ans;
        if(i>=1&&nums[i]==nums[i-1]) continue;
        int left=i+1,right=nums.size()-1;
        while(left<right)
        {
            long long x=static_cast<long long>(nums[i]);
            long long y=static_cast<long long>(nums[left]);
            long long z=static_cast<long long>(nums[right]);

            if(x+y==0-z) 
            {
                ans.push_back({nums[i], nums[left], nums[right]});          
                while(left<right&&nums[left]==nums[left+1])
                {
                    left++;
                }
                while(left<right&&nums[right-1]==nums[right])
                {
                    right--;
                }
                left++;
                right--;
            }
            if(x+y>0-z)
            {
                right--;
            }
            if(x+y<0-z)
            {
                left++;
            }
        }
    }
    return ans;
}

int main(void)
{
    vector<int>nums={0,0,0,0};
    vector<vector<int>> ans=threeSum(nums);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }
    system("pause");
    return 0;
    
}