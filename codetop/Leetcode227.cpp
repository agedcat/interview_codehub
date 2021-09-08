#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int calculate(string s){
    if(s.empty()) return 0;

    stack<int>stokens;
    int num = 0;
    char op = '+';
    int pre = 0;
    for(int i = 0;i < s.size();++i){
        if(isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1){
            switch (op)
            {
            case '+':
                stokens.push(num);
                break;

            case '-':
                stokens.push(-num);
                break;

            case '*':
                pre = stokens.top();
                stokens.pop();
                stokens.push(pre * num);
                break;

            case '/':
                pre = stokens.top();
                stokens.pop();
                stokens.push(pre / num);
                break;
            }
            op = s[i];
            num = 0;
        }
    }

    int ans = 0;
    while(!stokens.empty()){
        ans += stokens.top();
        stokens.pop();
    }

    return ans;
}

int main(void){
    string s = "3+2*2";
    cout << calculate(s) <<endl;
    return 0;
}