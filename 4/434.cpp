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

/*
思路：Union Find  并查集
1.首先，要动态地记录每加入一个岛屿之后、陆地数量是多少，在线算法？并查集来实现。
2.这里有个小技巧，二维坐标转化为一维坐标：col * x + y
*/

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:

    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        
        vector<int> ans;
        
        int xs[4] = {0, 0, 1, -1};
        int ys[4] = {1, -1, 0, 0};
        
        for (int i = 0; i < operators.size(); ++i) {
            int x = operators[i].x, y = operators[i].y;
            int coordinate = m * x + y;
            if (fathers.find(coordinate) != fathers.end()) {
                ans.push_back(total);
                continue;
            }
            total++;
            fathers[coordinate] = coordinate;
            for (int j = 0; j < 4; ++j) {
                int X = x + xs[j];
                int Y = y + ys[j];
                int COORDINATE = m * X + Y;
                if (!(X >= 0 && X < n && Y >= 0 && Y < m)) {
                    continue;
                }
                if (fathers.find(COORDINATE) == fathers.end()) {
                    continue;
                }
                //Union merge
                Union(coordinate, COORDINATE);
            }
            ans.push_back(total);
        }
        
        return ans;
    }
    
private:
    int total = 0;
    unordered_map<int, int> fathers;
    
    int Find (int i) {
        if (fathers[i] == i) {
            return i;
        }
        return fathers[i] = Find(fathers[i]);
    }
    
    void Union (int coordinate, int COORDINATE) {
        int dadOld = Find(COORDINATE);
        int dadNew = Find(coordinate);
        if (dadOld != dadNew) {
            fathers[dadNew] = dadOld;
            total--;
        }
    }
};
