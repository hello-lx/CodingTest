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
    bool is_empty_space(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= grid.size() ||
            y < 0 || y >= grid[0].size()) {
            return false;
        }
        if (grid[x][y] != 0) {
            return false;
        }
        return true;
    }
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }
        int row = grid.size();
        int col = grid[0].size();
        
        // find all houses
        vector<pair<int,int>> houses;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    houses.push_back(make_pair(i,j));
                }
            }
        }
        
        // distance (sum) from different houses to this point
        vector<vector<int>> dist(row, vector<int>(col,0)); 
        // how many houses reaches this point
        vector<vector<int>> reach(row, vector<int>(col,0));

        // bfs from *each* houses
        for (auto house : houses) {
            // bfs
            queue<pair<int,int>> q;
            vector<vector<bool>> visited(row, vector<bool>(col,false));
            q.push(house);
            visited[house.first][house.second] = true; // this is not necessary here
            int steps = 0;
            
            while (!q.empty()) {
                int size = q.size();
                steps++;
                for (int i = 0; i < size; i++) {
                    pair<int,int> cur = q.front(); q.pop();
                    for (auto d : dir) {
                        int x = cur.first + d[0];
                        int y = cur.second + d[1];
                        if (!is_empty_space(x, y, grid) || visited[x][y]) {
                            continue;
                        }
                        reach[x][y] ++;
                        dist[x][y] += steps;
                        q.push(make_pair(x,y));
                        visited[x][y] = true;
                    }
                }              
            }
        }
        
        int res = INT_MAX;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0 && reach[i][j] == houses.size()) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return (res == INT_MAX) ? -1 : res;
        
    }

private:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
};
