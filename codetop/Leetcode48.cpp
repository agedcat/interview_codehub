#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    //主对角线翻转
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //垂直中线翻转
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n/2;++j)
        {
            swap(matrix[i][j],matrix[i][n-j-1]);
        }
    }
}

int main(void)
{
    vector<vector<int>>matrix={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate(matrix);
    for(int i=0;i<matrix.size();++i)
    {
        for(int j=0;j<matrix.size();++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}