#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//方法一：穷举
bool repeatedSubstringPattern1(string s)
{
    int n=s.size();
    for(int i=1;i*2<n;i++)
    {
        if(n%i==0)
        {
            bool match=true;
            for(int  j=i;j<n;j++)
            {
                if(s[j]!=s[j-i])
                {
                    match=false;
                    break;
                }
            }
            if(match) return true;
        }
    }
    return false;

}

//方法二：字符串匹配
bool repeatedSubstringPattern2(string s)
{
    return (s+s).find(s,1)!=s.size();
}

