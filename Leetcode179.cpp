#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string largestNumber(vector<int>& nums)
{
    if(nums.empty()) return "";
    vector<string>trans;
    for(auto x:nums)
    {
        trans.push_back(to_string(x));
    }
    sort(trans.begin(),trans.end(),[](string& a,string& b)
    {
        return a+b>b+a;
    });
    if(trans[0]=="0") return "0";
    string res="";
    for(auto x:trans)
    {
        res+=x;
    }
    return res;
}

int main(void)
{
    vector<int>nums={3,30,34,5,9};
    cout<<largestNumber(nums)<<endl;
    return 0;
}