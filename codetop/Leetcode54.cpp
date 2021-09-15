#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int>res;
    if(matrix.size()==0||matrix[0].size()==0) 
    {
        return {};
    }
    int top=0;
    int bottom=matrix.size()-1;
    int left=0;
    int right=matrix[0].size()-1;

    while(top<=bottom && left<=right)
    {
        if(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;++i)
            {
                res.push_back(matrix[top][i]);
            }
        }
        top++;
        if(top<=bottom && left<=right)
        {
            for(int i=top;i<=bottom;++i)
            {
                res.push_back(matrix[i][right]);
            }
        }
        right--;
        if(top<=bottom && left<=right)
        {
            for(int i=right;i>=left;--i)
            {
                res.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(top<=bottom && left<=right)
        {
            for(int i=bottom;i>=top;--i)
            {
                res.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return res;
}

int main(void)
{
    vector<vector<int>>matrix={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int>res;
    res=spiralOrder(matrix);
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}