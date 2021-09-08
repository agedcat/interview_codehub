#include<iostream>
#include<vector>
using namespace std;

// int findLength(vector<int>&nums1,vector<int>&nums2)
// {
//     int ans=0;
//     vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
//     for(int i=0;i<nums1.size();++i)
//     {
//         for(int j=0;j<nums2.size();++j)
//         {
//             if(nums1[i]==nums2[j])
//             {
//                 dp[i+1][j+1]=dp[i][j]+1;
//             }
//             else{
//                 dp[i+1][j+1]=0;
//             }
//             ans=max(ans,dp[i+1][j+1]);
//         }
//     }
//     return ans;
// }

int maxLength(vector<int>&nums1,vector<int>&nums2,int add1,int add2,int length)
{
    int count=0,ret=0;
    for(int i=0;i<length;++i)
    {
        if(nums1[add1+i]==nums2[add2+i])
        {
            count++;
        }
        else{
            count=0;
        }
        ret=max(ret,count);
    }
    return ret;
}

int findLength(vector<int>&nums1,vector<int>&nums2)
{
    int ret=0;
    for(int i=0;i<nums1.size();++i)
    {
        int len=min(nums2.size(),nums1.size()-i);
        int maxlen=maxLength(nums1,nums2,i,0,len);
        ret=max(ret,maxlen);
    }
    for(int i=0;i<nums2.size();++i)
    {
        int len=min(nums1.size(),nums2.size()-i);
        int maxlen=maxLength(nums1,nums2,0,i,len);
        ret=max(ret,maxlen);
    }
    return ret;

}

int main(void)
{
    vector<int>nums1={1,2,3,2,1};
    vector<int>nums2={3,2,1,4,7};
    int ans=findLength(nums1,nums2);
    cout<<ans<<endl;
    return 0;
}