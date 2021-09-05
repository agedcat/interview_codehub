#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>merge(vector<vector<int>>&intervals)
{
    if(intervals.empty()) return {};
    sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){ return (a[0]<b[0]);});
    vector<vector<int>>ans;
    int L=intervals[0][0],R=intervals[0][1];
    ans.push_back({L,R});
    for(int i=1;i<intervals.size();++i)
    {
        if(intervals[i][0]<=ans.back()[1]&&intervals[i][1]>ans.back()[1])
        {
            ans.back()[1]=intervals[i][1];
        }
        else if(intervals[i][0]>ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

int main(void)
{
    vector<vector<int>>intervals={
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    vector<vector<int>>ans=merge(intervals);
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;

}