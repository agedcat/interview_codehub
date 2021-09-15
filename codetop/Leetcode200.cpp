#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<char>>&grid,vector<vector<bool>>&visited,int i,int j)
{
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return;
    if(grid[i][j]=='1'&&visited[i][j]==false)
    {
        visited[i][j]=true;
        DFS(grid,visited,i-1,j);
        DFS(grid,visited,i+1,j);
        DFS(grid,visited,i,j-1);
        DFS(grid,visited,i,j+1);
    }
}

int numIslands(vector<vector<char>>& grid)
{
    vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
    int res=0;
    for(int i=0;i<grid.size();++i)
    {
        for(int j=0;j<grid[0].size();++j)
        {
            if(!visited[i][j]&&grid[i][j]=='1') res++;
            DFS(grid,visited,i,j);
        }
    }
    return res;
}

int main(void)
{
    vector<vector<char>>grid={
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int res=0;
    res=numIslands(grid);
    cout<<res<<endl;
    return 0;

}