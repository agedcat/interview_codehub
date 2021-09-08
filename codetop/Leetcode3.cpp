#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;



int lengthoflongestSubstring(string s)

{
    map<char,bool>mp;
    vector< int >dp;
    dp.push_back(1);
    mp[s[0]]=true;
    int count=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1]) 
        {
            dp.push_back(1);
            mp.clear();
            mp[s[i]]=true;
            count=0;
        }
        else if(s[i]!=s[i-1]&&mp[s[i]])
        {
            count++;
            dp.push_back(count);
            mp.clear();
            for(int j=i-count+1;j<=i;j++) mp[s[j]]=true;
            //mp[s[i-1]]=true;
           // mp[s[i]]=true;
        }
        else 
        {
            count++;
            dp.push_back(dp[i-1]+1);
            mp[s[i]]=true;
        }
    }
    int ans=0;
    for(int i=0;i<dp.size();i++)
    {
        if(dp[i]>ans) ans=dp[i];
    }
    return ans;
}

int lengthoflongestSubstring1(string s)
{
    int n=s.size();
    int i=0,j=0;
    map<char,bool>mp;
    int ans=0;
    while(j<n||mp[s[j]])
    {
        if(j==0||!mp[s[j]])
        {
            mp[s[j]]=true;
            j++;
            ans=max(ans,j-i);
        }
        else
        {          
            mp.erase(s[i]);
            i++;
            ans=max(ans,j-i);
        }
    }
    return ans;


}


int main()
{
    string  s="bbbbb";
    int ans=lengthoflongestSubstring1(s);
    cout<<ans<<endl;
    system("pause");
    return 0;
}