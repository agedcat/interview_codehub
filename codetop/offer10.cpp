#include<iostream>
#include<vector>
using namespace std;

int numWays(int n){
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; ++i){
        dp[i] = (i >= 1 ? dp[i - 1] : 0) + (i >= 2 ? dp[i - 2] : 0);
    }

    return dp[n] % 1000000007;
}

int main(void)
{
    int n = 44;
    cout << numWays(n) << endl;
    return 0;
}