#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INT_MIN -99999999999
#define INT_MAX 99999999999

// DFS
class Solution {
public:
    void dfs(vector<vector<bool>> &grid, int row, int col)
    {
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0; i<4; i++)
        {
            int nx = row + dx[i], ny = col + dy[i];
            if(nx>=0 && nx < rows && ny>=0 && ny<cols && grid[nx][ny])
            {
                grid[nx][ny] = false;
                dfs(grid, nx, ny);
            }
        }
    }

    int numIslands(vector<vector<bool>> &grid) {
        if(grid.size() == 0) return grid.size();
        
        int rows = grid.size(), cols = grid[0].size();
        int N = 0;
        for(int row=0; row<rows; row++)
        {
            for(int col=0; col<cols; col++)
            {
                if(grid[row][col])
                {
                    N++;
                    dfs(grid, row, col);
                }
            }
        }

        return N;
    }
};

/* BFS time out */
class Solution2 {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int rows=grid.size(), cols=grid[0].size();        
        int numIsland=0;

        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int row=0; row<rows; row++)
        {
            for(int col=0; col<cols; col++)
            {
                if(grid[row][col] == 1)
                {
                    numIsland++;
                    Q.push({row, col});
                    while(!Q.empty())
                    {
                        auto cur = Q.front();
                        Q.pop();
                        
                        grid[cur.first][cur.second] = 0;

                        for(int i=0; i<4; i++)
                        {
                            int nx = cur.first + dx[i];
                            int ny = cur.second + dy[i];
                            if(nx>=0 && nx < rows && ny>=0 && ny<cols && grid[nx][ny] == 1)
                                Q.push({nx, ny});
                        }
                    }
                }
                
            }
        }

        return numIsland;
    }

private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
};
