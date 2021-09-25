#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

string decodeString(string s){
    if(s.empty()) return "";

    string ans = "";
    stack<string> st;
    stack<int> nums;
    int num = 0;

    for(int i = 0; i < s.size(); ++i){
        if(isdigit(s[i])){
            num = num * 10 + s[i] - '0';
        }else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            ans += s[i];
        }else if(s[i] == '['){
            nums.push(num);
            num = 0;
            st.push(ans);
            ans = "";
        }else if(s[i] == ']'){
            int times = nums.top();
            nums.pop();
            for(int j = 0; j < times; ++j){
                st.top() += ans;
            }
            ans = st.top();
            st.pop();
        }
    }

    return ans;
}

int main(void)
{
    string s = "abc3[cd]xyz";
    cout << decodeString(s) << endl;
    return 0;
}