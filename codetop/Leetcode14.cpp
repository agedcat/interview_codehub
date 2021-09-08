#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    if(strs.size() == 0) return "";
    if(strs.size() == 1) return strs[0];

    bool commonPrefix = false;

    string prefix = "";
    for(int i = 0; i < strs[0].size(); ++i){
        for(int j = 1; j < strs.size(); ++j){
            if(strs[j][i] != strs[0][i]){
                commonPrefix = true;
                break;
            }
        }
        if(commonPrefix) break;
        prefix += strs[0][i];
    }

    return prefix;
}

int main(void)
{
    vector<string>strs = {"dog","racecar","car"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}