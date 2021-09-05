#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// vector<vector<int>>ans;

// void DFS(vector<int>& candidates,int target,vector<int>&temp,int index)
// {
//     if(target==0)
//     {
//         ans.push_back(temp);
//         return;
//     }
//     for(int i=index;i<candidates.size();++i)
//     {
//         if(target<candidates[i]) break;
//         temp.push_back(candidates[i]);
//         DFS(candidates,target-candidates[i],temp,i);
//         temp.pop_back();
//     }

// }

// vector<vector<int>> combinationSum(vector<int>& candidates, int target)
// {
//     if(candidates.empty()) return {};
//     sort(candidates.begin(),candidates.end());
//     vector<int>temp;
//     DFS(candidates,target,temp,0);
//     return ans;
// }

// int main(void)
// {
//     vector<int>nums={2,3,6,7};
//     int target=7;
//     combinationSum(nums,target);
//     for(int i=0;i<ans.size();++i)
//     {
//         for(int j=0;j<ans[i].size();++j)
//         {
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


vector<vector<int>>ans;

void DFS(vector<int>& candidates,int target,vector<int>temp,int index)
{
    if(target<0||index>=candidates.size())
    {    
        return;
    } 
    if(target<candidates[index])
    {
        index=candidates.size();
    }
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }

    DFS(candidates,target,temp,index+1);
    temp.push_back(candidates[index]);
    DFS(candidates,target-candidates[index],temp,index);

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    if(candidates.empty()) return {};
    sort(candidates.begin(),candidates.end());
    vector<int>temp;
    DFS(candidates,target,temp,0);
    return ans;
}

int main(void)
{
    vector<int>nums={2,3,6,7};
    int target=7;
    combinationSum(nums,target);
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
