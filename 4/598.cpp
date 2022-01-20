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


// 2 代表墙，1 代表僵尸，0 代表人类(数字 0, 1, 2)

/*
因为矩阵只有0-人，1-僵尸，2-墙所以僵尸每天只能吃相邻位置的人。（1step）
故可用bfs。将僵尸初始位置push进queue，检查僵尸吃完所有人需要多少天(分层)。
两种检查方法：1）矩阵有没有0 2）visited是不是已经所有点都访问。

多源点bfs。
*/

class Solution {
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // write your code here
        //wall -2 
        //zombie - 1
        //people - 0
        int n = grid.size();
        if (n == 0) {
            return -1;
        }
        int m = grid[0].size();// n * m
        if (isComplelte(grid)) {
            return 0;
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        queue<pair<int, int>> Q;
        unordered_map<int, unordered_map<int,int>> visited;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    pair<int,int> p(i, j);
                    Q.push(p);
                    visited[i][j] = 1;
                }
            }
        }
        int day = 1;
        while (!Q.empty()) {
            int l = Q.size();
            while (l > 0) {
                pair<int, int> f = Q.front();
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int x_ = f.first + dx[i];
                    int y_ = f.second + dy[i];
                    if (x_ < 0 || x_ >= n) {
                        continue;
                    }
                    if (y_ < 0 || y_ >= m) {
                        continue;
                    }
                    pair<int, int> temp(x_, y_);
                    if (visited.count(x_) != 0 && visited[x_].count(y_) != 0) 
                    {
                        continue;
                    }
                    if (grid[x_][y_] == 2) 
                    {
                        continue;
                    }
                    if (grid[x_][y_] == 0) 
                    {
                        grid[x_][y_] = 1;
                        // pair<int, int> temp(x_, y_);
                        Q.push(temp);
                        visited[x_][y_] = 1;
                    }
                }
                l--;
            }
            if (isComplelte(grid)) {
                return day;
            }
            day++;
        }
        return -1;
    }
    
    bool isComplelte(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};