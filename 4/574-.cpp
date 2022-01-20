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



class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }
        
        int row = grid.size(), col = grid[0].size();
        
        // property of L1 distance, can separate x and y
        vector<int> rowCount(row, 0);
        vector<int> colCount(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != 1) {
                    continue;
                }
                // # houes in row i
                rowCount[i]++;
                // # houes in col j
                colCount[j]++;
            }
        }
        
        // get cost in x, y direction separately
        vector<int> rowCost = getCost(rowCount);
        vector<int> colCost = getCost(colCount);
        
        // L1 distance, x + y, separable
        const int inf = numeric_limits<int>::max();
        int ans = inf;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != 0) {
                    continue;
                }
                ans = min(ans, rowCost[i] + colCost[j]);
            }
        }
        
        return ans == inf ? -1 : ans;
    }
private:
    // O(n^2)
    vector<int> getCost(vector<int> &count) {
        int n = count.size();
        vector<int> cost(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i] += count[j] * abs(j - i);
            }
        }
        return cost;
    }

};