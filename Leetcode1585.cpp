#include<iostream>
#include<string>
#include<vector>
#include<queue>
using  namespace std;

bool isTransformable(string s,string t)
{
    int n=s.size();
    vector<queue<int>>pos(10);
    //将s字符串中‘0-9’的数字的标号记录到每个相应的队列中
    for(int i=0;i<n;i++) pos[s[i]-'0'].push(i);
    for(int i=0;i<n;i++)
    {
        int digit=t[i]-'0';
        if(pos[digit].empty()) return false;
        for(int j=0;j<digit;j++)
        {
            if(!pos[j].empty()&&pos[j].front()<pos[digit].front()) return false;

        }
        pos[digit].pop();
    }
    return true;
}

int main(void)
{
    string s="84532";
    string t="34852";
    bool flag=isTransformable(s,t);
    if(flag) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    system("pause");
    return 0;

}