#include <vector>
using namespace std;


class Solution {
public:
    /*
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        if(m==0 || n==0) return 0;
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> path(m, vector<int>(n, 0));
        path[0][0] = 1;
        for(int  i=1; i<m; i++){
            if(obstacleGrid[i][0] == 1) path[i][0] = 0;
            else path[i][0] = path[i-1][0];
        }
        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j] == 1) path[0][j] = 0;
            else path[0][j] = path[0][j-1];
        }
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1) path[i][j] = 0;
                else path[i][j] = path[i-1][j] + path[i][j-1];
            }
            
        return path[m-1][n-1];
        
    }
};
