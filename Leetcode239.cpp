#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow1(vector<int>& nums, int k)
{
    vector<int>ans;
    for(int i=0;i<nums.size()-k+1;++i)
    {
        int tempMax=*max_element(nums.begin()+i,nums.begin()+i+k);
        ans.push_back(tempMax);
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    if(k<2) return nums;
    deque<int>window;
    vector<int>ans;
    //处理第一个窗口的情况
    for(int i=0;i<k;++i)
    {
        //比较新的数和window的末尾
        while(!window.empty()&&nums[window.back()]<nums[i])
        {
            window.pop_back();
        }
        //末尾加入新数
        window.push_back(i);
    }
    //保存窗口的最大值
    ans.push_back(nums[window.front()]);

    for(int i=k;i<nums.size();++i)
    {
        //保证队列中存储的下标必须在窗口内
        if(!window.empty()&&window.front()<i-k+1||window.front()>i)
        {
            window.pop_front();
        }
        //比较新的数和window的末尾
        while(!window.empty()&&nums[window.back()]<nums[i]) 
        {
            window.pop_back();
        }
        //末尾加入新数
        window.push_back(i);
        ////保存窗口的最大值
        ans.push_back(nums[window.front()]);
    }
    return ans;
}

int main(void)
{
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    //vector<int>nums={9,11};
    int k=3;
    vector<int>ans;
    ans=maxSlidingWindow(nums,k);
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

