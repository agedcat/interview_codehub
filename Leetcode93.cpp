#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string>ans;

void DFS(string& s,int count,int index,string& str)
{
    if(count==4||index==s.size())
    {
        if(count==4&&index==s.size())
        {
            ans.push_back(str.substr(0,str.size()-1));
        }
        return;
    }

    for(int cnt=1;cnt<=3;++cnt)
    {
        if(index+cnt+3-count>s.size()) return;
        //if(s[index]=='0'&&index==0) return;
        if(s[index]=='0'&&cnt!=1) return;
        if(cnt==3&&s.substr(index,cnt)>"255") return;

        str+=s.substr(index,cnt);
        str+='.';
        DFS(s,count+1,index+cnt,str);
        str=str.substr(0,str.size()-cnt-1);       
    }
}

void dfs(string&s,int index,int count,string& str)
{
    if(count>=4||index>=s.size())
    {
        if(count==4&&index==s.size())
        {
            ans.push_back(str.substr(0,str.size()-1));
        }
        return;
    }
    

    for(int cnt=1;cnt<=3;++cnt)
    {
        if(index+cnt+3-count>s.size()) return;
        if(s[index]=='0'&&cnt!=1) return;
        if(cnt==3&&s.substr(index,cnt)>"255") return;

        str+=s.substr(index,cnt);
        str+='.';
        dfs(s,index+cnt,count+1,str);
        str=str.substr(0,str.size()-cnt-1);
    }
}

vector<string> restoreIpAddresses(string s)
{
    string str="";
    //DFS(s,0,0,str);
    dfs(s,0,0,str);
    return ans;
}

int main(void)
{
    string s="25525511135";
    vector<string>ans;
    ans=restoreIpAddresses(s);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

