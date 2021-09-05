#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

int longestConsecutive(vector<int>& nums){
    unordered_set<int>nums_set;
    for(auto &num : nums){
        nums_set.insert(num);
    }

    int curLength=0;
    int longestLength=0;
    for(auto &num : nums){
        if(nums_set.count(num-1)){
            continue;
        }
        if(!nums_set.count(num-1)){
            curLength = 1;
        }
        int index = num + 1;
        while(nums_set.count(index)){
            curLength++;
            index++;
        }
        longestLength = curLength > longestLength ? curLength : longestLength;
    }
    return longestLength;
}

int main(void)
{
    vector<int>nums = {100, 4, 200, 1, 3, 2};
    cout<<longestConsecutive(nums)<<endl;
    return 0;
}