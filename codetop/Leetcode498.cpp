#include<iostream>
#include<vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat){
    if(mat.empty()) return {};

    int rows = mat.size();
    int cols = mat[0].size();
    int row = 0, col = 0;
    int direction = 1;
    vector<int> result;

    while(row < rows && col < cols){
        result.emplace_back(mat[row][col]);

        int newRow = row + (direction == 1 ? -1 : 1);
        int newCol = col + (direction == 1 ? 1 : -1);

        if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols){
            if(direction == 1){
                if(col < cols - 1){
                    col += 1;
                }
                else if(col == cols - 1){
                    row += 1;
                }
            }else{
                if(row < rows - 1){
                    row += 1;
                }
                else if(row == rows - 1){
                    col += 1;
                }
            }
            direction = 1 - direction;
        }else{
            row = newRow;
            col = newCol;
        }
    }
    return result;
}

int main(void)
{
    vector<vector<int>>mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    vector<int>result = findDiagonalOrder(mat);

    for(auto e : result){
        cout << e << " " ;
    }
    return 0;
}