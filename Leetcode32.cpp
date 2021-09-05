#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

// int longestValidParentheses(string s){
//     int n = s.size();
//     vector<int>dp(n,0);

//     int ans = 0;
//     for(int i = 1;i < n;++i){
//         if(s[i] == ')'){
//             if(s[i-1] == '('){
//                 dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
//             }else if(i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '('){
//                 dp[i] = dp[i-1] + (i-dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
//             }
//         }
//         ans = dp[i] > ans ? dp[i] : ans;
//     }
//     return ans;   
// }

// int longestValidParentheses(string s){
//     stack<int>st;
//     int ans=0;

//     st.push(-1);
//     for(int i=0;i<s.size();++i){
//         if(s[i]=='('){
//             st.push(i);
//         }else{
//             st.pop();
//             if(st.empty()){
//                 st.push(i);
//             }else{
//                 ans=i-st.top()>ans?i-st.top():ans;
//             }
//         }
//     }
//     return ans;
// }

int longestValidParentheses(string s){
    int left=0,right=0,ans=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            left++;
        }else{
            right++;
        }
        if(left==right){
            ans=2*right>ans?2*right:ans;
        }else if(right>left){
            left=right=0;
        }
    }

    left=right=0;
    for(int i=s.size()-1;i>0;--i){
        if(s[i]=='('){
            left++;
        }else{
            right++;
        }
        if(left==right){
            ans=2*left>ans?2*left:ans;
        }else if(left>right){
            left=right=0;
        }
    }

    return ans;
}

int main(void)
{
    string s = "()()";
    cout<<longestValidParentheses(s)<<endl;
    return 0;
}