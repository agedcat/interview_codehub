#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n)
{
    vector<int>dp(n+1,1);
    for(int i=2;i<=n;++i)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(void)
{
    int n=2;
    cout<<climbStairs(n)<<endl;
}