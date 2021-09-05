#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// vector<int>dp;

// int dfs(int amount,vector<int>& coins)
// {
//     if(amount<0) return -1;
//     if(amount==0) return 0;
//     if(dp[amount]!=0) return dp[amount];

//     int minSum=INT32_MAX;
//     for(int i=0;i<coins.size();++i)
//     {
//         int t=dfs(amount-coins[i],coins);
//         if(t>=0&&t<minSum) minSum=t+1;
//     }
//     dp[amount]=minSum==INT32_MAX?-1:minSum;
//     return dp[amount];
// }

// int coinChange(vector<int>& coins, int amount)
// {
//     if(amount<1) return 0;
//     dp.resize(amount+1);
//     return dfs(amount,coins);
// }

int coinChange(vector<int>& coins, int amount)
{
    if(amount<1) return 0;
    int maxSum=amount+2;
    vector<int>dp(amount+1,maxSum);
    dp[0]=0;
    for(int i=1;i<=amount;++i)
    {
        for(int j=0;j<coins.size();++j)
        {
            if(i>=coins[j])
            {
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return dp[amount]>amount?-1:dp[amount];
}

int main(void)
{
    vector<int>coins={186,419,83,408};
    int amount=6249;
    cout<<coinChange(coins,amount)<<endl;
    return 0;
}