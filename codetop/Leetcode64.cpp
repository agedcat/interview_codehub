#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int rowNum = grid.size();       //行数
    int colNum = grid[0].size();    //列数
    vector<vector<int>> dp(rowNum,vector<int>(colNum,0));
    dp[0][0]=grid[0][0];
    for(int i=1;i<colNum;++i)
    {
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    for(int i=1;i<rowNum;++i)
    {
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int row=1;row<rowNum;++row)
    {
        for(int col=1;col<colNum;++col)
        {
            //从上边或左边耗费更小的一格走到当前
            dp[row][col]=min(dp[row-1][col],dp[row][col-1])
                            +grid[row][col];
        }
    }
    return dp[rowNum-1][colNum-1];
}