/*
def minPathSum(self, grid):
    # write your code here
    #定义一个相同形状的数组
    n = len(grid)
    m = len(grid[0])
    dp = grid
    #左上角的路径和为自身。
    # 因为只能向右或者向下移动，所以第一行和第一列只能由上一位移动来
    for i in range(1, m):
        dp[0][i] = dp[0][i-1] + grid[0][i]
    for i in range(1, n):
        dp[i][0] = dp[i-1][0] + grid[i][0]
    
    # 记录其他位置的最优路径和，只能从上或者右，所以选择最优
    for i in range(1, n):
        for j in range(1, m):
            dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])
    return dp[n-1][m-1]
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int rows = grid.size();
        int cols = grid[0].size();

        for(int row=1; row<rows; row++)
            grid[row][0] = grid[row-1][0] + grid[row][0];
        for(int col=1; col<cols; col++)
            grid[0][col] = grid[0][col-1] + grid[0][col];
        
        for(int i=1; i<rows; i++)
            for(int j=1; j<cols; j++)
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
                
        return grid[rows-1][cols-1];
    }
};
