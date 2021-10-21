#include<iostream>
#include<vector>
using namespace std;

int numWays(int n){
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 0);
    }

    return dp[n] % 1000000007;
}

int numWays(int n){
    int a = 1;
    int b = 1;

    if(n == 0 || n == 1) return 1;

    for(int i = 2; i <= n; ++i){
        int t = (a % 1000000007 + b % 1000000007) % 1000000007;
        b = a;
        a = t;
    }

    return a;
}

int main(void)
{
    int n = 44;
    cout << numWays(n) << endl;
    return 0;
}