#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// int minSubArrayLen(int target, vector<int>& nums){
//     if(nums.empty()) return 0;

//     int left = 0, right = 0;
//     int sum = nums[0];
//     if(sum >= target) return 1;

//     int ans = INT32_MAX;
//     while(right < nums.size()){
//         if(sum < target){
//             right++;
//             if(right < nums.size()){
//                 sum += nums[right];
//             }
//         }else{
//             ans = right -left + 1 > ans ? ans : right -left + 1;
//             sum -= nums[left++];
//         }

//     }
//     return ans == INT32_MAX ? 0 : ans;
// }

int minSubArrayLen(int target, vector<int>& nums){
    if(nums.empty()) return 0;


    vector<int> sums(nums.size() + 1, 0);
    for(int i = 1; i <= nums.size(); ++i){
        sums[i] = sums[i - 1] + nums[i - 1];
    }

    int ans = INT32_MAX;
    for(int i = 1; i <= nums.size(); ++i){
        int s = sums[i - 1] + target;
        auto index = lower_bound(sums.begin(), sums.end(), s);
        if(index != sums.end()){
            ans = min(ans, static_cast<int>((index - sums.begin()) - (i - 1)));
        }
    }

    return ans == INT32_MAX ? 0 : ans;
}

int main(void)
{
    vector<int>nums = {2, 3, 1, 2, 4, 3};
    int target = 17;
    cout << minSubArrayLen(target, nums);
    return 0;
}