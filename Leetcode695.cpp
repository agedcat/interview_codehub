#include<iostream>
#include<vector>
using namespace std;

int DFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
    if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1){
        return 0;
    }

    if(visited[i][j]){
        return 0;
    }

    visited[i][j] = 1;
    if(grid[i][j] == 1){
        return DFS(grid, visited, i - 1, j) + DFS(grid, visited, i + 1, j) + DFS(grid, visited, i, j - 1) + DFS(grid, visited, i, j + 1) + 1;
    }
    return 0;
}


int maxAreaOfIsland(vector<vector<int>>& grid){
    if(grid.empty()){
        return 0;
    }

    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    int ans = 0;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            if(!visited[i][j]){
                ans = max(DFS(grid, visited, i, j), ans);
            }   
        }
    }

    return ans; 
}

int main(void){
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0},
    };
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}