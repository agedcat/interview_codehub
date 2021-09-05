//全排列

#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<int>&nums,vector<bool>&visited,vector<vector<int>>&res,vector<int>&path)
{
    if(path.size()==nums.size())
    {
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();++i)
    {
        if(!visited[i])
        {
            visited[i]=true;
            path.push_back(nums[i]);
            DFS(nums,visited,res,path);
            visited[i]=false;
            path.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>>res;
    vector<int>path;
    vector<bool>visited(nums.size(),false);
    DFS(nums,visited,res,path);
    return res;
}

int main(void)
{
    vector<int>nums={1,2,3};
    vector<vector<int>>res;
    res=permute(nums);
    for(int i=0;i<res.size();++i)
    {
        for(int j=0;j<res[0].size();++j)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}