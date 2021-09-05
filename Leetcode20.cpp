#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<string.h>
#include<vector>
#include<algorithm>
#include<sstream>
#include<climits>
#include<Stack>
using namespace std;

bool isValid(string s)
{
    int n=s.size();
    if(n%2==1) return false;

    unordered_map<char,char>mp={
        {')','('},
        {']','['},
        {'}','{'}
    };

    stack<char>st;

    for(int i=0;i<s.size();++i)
    {
        if(mp.count(s[i])) 
        {
            if(st.empty()||st.top()!=mp[s[i]]) return false;
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    return st.empty();




}