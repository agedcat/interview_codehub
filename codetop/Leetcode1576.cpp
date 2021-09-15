#include<iostream>
using namespace std;

string modifyString(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='?')
        {
            s[i]='a';
            while((i>0&&s[i]==s[i-1])||(i<s.size()-1&&s[i]==s[i+1])) s[i]+=1;
        }
    }
    return s;
}

int main(void)
{
    string s="ubv?w";
    cout<<modifyString(s)<<endl;
    system("pause");
    return 0;
}
