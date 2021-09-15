#include<vector>
#include<string>
#include<iostream>
using namespace std;

void DFS(vector<string>& ans, string& cur, int left, int right, int n){
    if(cur.size() == n * 2){
        ans.push_back(cur);
        return;
    }

    if(left < n){
        cur.push_back('(');
        DFS(ans,cur,left+1,right,n);
        cur.pop_back();
    }

    if(right < left){
        cur.push_back(')');
        DFS(ans,cur,left,right+1,n);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string>ans;
    string cur;
    DFS(ans,cur,0,0,n);
    return ans;
}

int main(void)
{
    vector<string>ans;
    ans = generateParenthesis(3);
    for(auto& s : ans){
        cout<<s<<endl;
    }
    return 0;
}