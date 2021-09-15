#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int trap(vector<int>&height)
// {
//     if(height.empty()) return 0;

//     vector<int>leftMax(height.size(),0);
//     leftMax[0]=height[0];
//     for(int i=1;i<height.size();++i)
//     {
//         leftMax[i]=max(leftMax[i-1],height[i]);
//     }

//     vector<int>rightMax(height.size(),0);
//     rightMax[height.size()-1]=height[height.size()-1];
//     for(int i=height.size()-2;i>=0;--i)
//     {
//         rightMax[i]=max(rightMax[i+1],height[i]);
//     }

//     int res=0;
//     for(int i=0;i<height.size();++i)
//     {
//         int curMin=min(leftMax[i],rightMax[i]);
//         if(curMin>height[i]) res+=curMin-height[i];
//     }

//     return res;
// }

int trap(vector<int>&height)
{
    int ans=0;
    int left=0,right=height.size()-1;
    int leftMax=0,rightMax=0;
    while(left<right)
    {
        leftMax=max(leftMax,height[left]);
        rightMax=max(rightMax,height[right]);
        if(height[left]<height[right])
        {
            ans+=leftMax-height[left];
            ++left;
        }
        else{
            ans+=rightMax-height[right];
            --right;
        }
    }
    return ans;
}

int main(void)
{
    vector<int>height={4,2,0,3,2,5};
    int res=trap(height);
    cout<<res<<endl;
    return 0;
}