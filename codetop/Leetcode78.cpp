#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>ans;

void DFS(vector<int>& nums,int index,vector<int>temp)
{
    if(index>=nums.size())
    {
        ans.push_back(temp);
        return;
    }
    DFS(nums,index+1,temp);
    temp.push_back(nums[index]);
    DFS(nums,index+1,temp);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    if(nums.empty()) return {{}};
    vector<int>temp;
    DFS(nums,0,temp);
    return ans;
}

int main(void)
{
    vector<int>nums={1,2,3};
    vector<vector<int>>ans;
    ans=subsets(nums);
    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[i].size();++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}