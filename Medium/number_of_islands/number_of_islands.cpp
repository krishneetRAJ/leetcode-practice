#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0){
            return 0;
        }
        int cols = grid[0].size();
        int islandCount = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1') {
                    islandCount++;

                    //Using vector<int> to store coordinates manually
                    stack<vector<int>> s;
                    s.push({i, j});

                    while(!s.empty()) {
                        vector<int> cell = s.top();
                        s.pop();
                        int r = cell[0];
                        int c = cell[1];

                        if(grid[r][c] == '0'){
                            continue;
                        }
                        grid[r][c] = '0'; // mark as visited

                        // Push neighbors if valid land
                        if(r > 0 && grid[r-1][c] == '1'){
                            s.push({r-1, c});
                        }
                        if(r < rows-1 && grid[r+1][c] == '1'){
                            s.push({r+1, c});
                        }
                        if(c > 0 && grid[r][c-1] == '1'){
                            s.push({r, c-1});
                        }
                        if(c < cols-1 && grid[r][c+1] == '1'){
                            s.push({r, c+1});
                        }
                    }
                }
            }
        }
        return islandCount;
    }
};

//Example usage
int main() {
    Solution solution1;
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Number of islands: " << solution1.numIslands(grid1) << endl;

    Solution solution2;
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of islands: " << solution2.numIslands(grid2) << endl;
    return 0;
}