#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

// string minWindow(string s, string t)
// {
//     vector<int>mp(128,0);
//     int totalCount=0;
//     for(int i=0;i<t.size();++i)
//     {
//         mp[t[i]]++;
//         totalCount++;
//     }

//     int i=0,j=0;
//     int minLen=INT32_MAX;
//     string ans="";
//     while (j<=s.size())
//     {
//         while(totalCount==0)
//         {
//             if(j-i<minLen)
//             {
//                 minLen=j-i;
//                 ans=s.substr(i,minLen);
//             }
//             mp[s[i]]++;
//             if(mp[s[i]]>0)
//             {
//                 totalCount++;
//             }       
//             i++;
//         }
//         if(mp[s[j]]>0)
//         {     
//             totalCount--;
//         }
//         mp[s[j]]--;
//         j++;
//     }
//     return ans;  
// }

string minWindow(string s, string t)
{
    unordered_map<char,int>mp;
    int totalCount=0;
    for(int i=0;i<t.size();++i)
    {
        mp[t[i]]++;
        totalCount++;
    }

    int i=0,j=0;
    int start=0;
    int minLen=INT32_MAX;
    while (j<=s.size())
    {
        while(totalCount==0)
        {
            if(j-i<minLen)
            {
                minLen=j-i;
                start=i;
            }
            mp[s[i]]++;
            if(mp[s[i]]>0)
            {
                totalCount++;
            }       
            i++;
        }
        if(mp[s[j]]>0)
        {     
            totalCount--;
        }
        mp[s[j]]--;
        j++;
    }
    string ans=minLen==INT32_MAX?"":s.substr(start,minLen);
    return ans;  
}

int main(void)
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<minWindow(s,t)<<endl;
    return 0;
}