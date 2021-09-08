#include<iostream>
#include<String>
#include<climits>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

// int myAtoi(string s)
// {
//     int ans=0;
//     bool isMin=false;
//     int i=0;
//     while(i<s.size()&&s[i]==' ')
//     {
//         ++i;
//     }
//     int start=i;
//     for(;i<s.size();++i)
//     {
//         if(s[i]=='-'&&i==start) 
//         {
//             isMin=true;
//         }
//         else if(s[i]=='+'&&i==start)
//         {
//             isMin=false;
//         }
//         else if(s[i]>='0'&&s[i]<='9')
//         {
//             if(isMin)

//             {
//                 if(ans<INT32_MIN/10||(ans==INT32_MIN/10&&(s[i]-'0')>-(INT32_MIN%10))) return INT32_MIN;
//                 ans=ans*10-(s[i]-'0');
//             }
//             else{
//                // cout<<s[i]<<" "<<ans<<" "<<INT32_MAX/10<<" "<<INT32_MAX%10<<endl;
//                 if(ans>INT32_MAX/10||(ans==INT32_MAX/10&&(s[i]-'0')>INT32_MAX%10)) return INT32_MAX;
//                 //ans=ans*10+s[i]-'0';
//                 ans=ans*10+(s[i]-'0');
//             }
//         }
//         else{
//             break;
//         }
         
//     }
//     return ans;
// }

class Automaton{
    string stat="start";
    unordered_map<string,vector<string>>table={
        {"start",{"start","signed","in_number","end"}},
        {"signed",{"end","end","in_number","end"}},
        {"in_number",{"end","end","in_number","end"}},
        {"end",{"end","end","end","end"}}
    };

    int get_col(char c)
    {
        if(isspace(c)) return 0;
        if(c=='+'||c=='-') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }

public:
    bool isEnd=false;
    int sign=1;
    long long ans=0;

    void deal(char c)
    {
        stat=table[stat][get_col(c)];
        if(stat=="in_number")
        {
            ans=ans*10+(c-'0');
            ans=sign==1?min(ans,(long long)INT32_MAX):min(ans,-(long long)INT32_MIN);
        }
        else if(stat=="signed")
        {
            sign=c=='+'?1:-1;
        }
        else if(stat=="end")
        {
            isEnd=true;
        }

    }


};

int myAtoi(string s)
{
    Automaton automaton;
    for(char c:s)
    {
        automaton.deal(c);
        if(automaton.isEnd) break;
    }
    return automaton.sign*automaton.ans;
    
}

int main(void)
{
    string s="-21474836460";
    string s1="2147483648";
    int ans=myAtoi(s);
    int res=myAtoi(s1);
    cout<<ans<<endl;
    cout<<res<<endl;
    return 0;
}
