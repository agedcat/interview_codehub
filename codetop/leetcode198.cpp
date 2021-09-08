#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums){
    if(nums.empty()) return 0;

    int ans = nums[0];
    vector<int>dp(nums.size());
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        dp[i] = max(dp[i - 1], (i >= 2 ? dp[i - 2] + nums[i] : nums[i]));
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(void)
{
    vector<int>nums = {2,7,9,3,1};
    cout << rob(nums) << endl;
    return 0;
}