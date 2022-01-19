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



/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        queue<pair<int, int>> q1, q2;
        vector<vector<bool>> visited1(grid.size(), vector<bool>(grid[0].size(), 0));
        vector<vector<bool>> visited2(grid.size(), vector<bool>(grid[0].size(), 0));
        
        q1.push({source.x, source.y});
        q2.push({destination.x, destination.y});
        visited1[source.x][source.y] = 1;
        visited2[destination.x][destination.y] = 1;
        
        vector<vector<int>> dirs = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
        int step = 0;
        while (q1.size() || q2.size()) {
            int size1 = q1.size();
            for (int i = 0; i < size1; i++) {
                pair<int, int> cur = q1.front(); q1.pop();
                if (visited2[cur.first][cur.second]) return step;
                for (vector<int> dir : dirs) {
                    int x = cur.first + dir[0];
                    int y = cur.second + dir[1];
                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] || visited1[x][y]) continue;
                    visited1[x][y] = 1;
                    q1.push({x,y});
                    
                }
            }
            step++;
            
            int size2 = q2.size();
            for (int i = 0; i < size2; i++) {
                pair<int, int> cur = q2.front(); q2.pop();
                if (visited1[cur.first][cur.second]) return step;
                for (vector<int> dir : dirs) {
                    int x = cur.first + dir[0];
                    int y = cur.second + dir[1];
                    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] || visited2[x][y]) continue;
                    visited2[x][y] = 1;
                    q2.push({x,y});
                    
                }
            }
            step++;
        }
        return -1;
    }
};