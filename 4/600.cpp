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
    1. BFS
    2. 二分 + 传入 flag
    3. 二分 + 传入静态函数指针 （优雅简洁推荐）
    4. 二分 + 传入非静态函数指针 （仅供了解非静态函数指针使用，不推荐）
*/

class Coordinate {
public:
    int x;
    int y;
    Coordinate(int _x, int _y):x(_x), y(_y) {}
};

class Solution1 {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */

    // 0 表示白色像素点，1 表示黑色像素点
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        int r = image.size();
        if (r == 0) {
            return 0;
        }
        int c = image[0].size();
        
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        queue<Coordinate> Q;
        Q.push(Coordinate(x, y));
        visited[x][y] = true;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        int xMin = r - 1;
        int xMax = 0;
        int yMin = c - 1;
        int yMax = 0;
        
        
        while (!Q.empty()) {
            Coordinate curr = Q.front();
            Q.pop();

            xMin = xMin < curr.x ? xMin : curr.x;
            xMax = xMax > curr.x ? xMax : curr.x;
            yMin = yMin < curr.y ? yMin : curr.y;
            yMax = yMax > curr.y ? yMax : curr.y;
            
            for (int k = 0; k < 4; ++k) {
                int nx = curr.x + dx[k];
                int ny = curr.y + dy[k];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && visited[nx][ny] == false && image[nx][ny] == '1') {
                    visited[nx][ny] = true;
                    Q.push(Coordinate(nx, ny));
                }
            }
        }
        
        return (xMax - xMin + 1) * (yMax - yMin + 1);        
    }
};

class Solution2 {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */

    int minArea(vector<vector<char>> &image, int x, int y) {

        int n = image.size();
        int m = image[0].size();

        int x_min = findFirstNotAllZero(image, 0, x, true);
        int x_max = findLastNotAllZero(image, x, n - 1, true);
        int y_min = findFirstNotAllZero(image, 0, y, false);
        int y_max = findLastNotAllZero(image, y, m - 1, false);
        
        return (1 + x_max - x_min) *  (1 + y_max - y_min);
        
    }

    int findFirstNotAllZero(vector<vector<char>> &image, int start, int end, bool is_row) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isAllZero(mid, is_row, image)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int findLastNotAllZero(vector<vector<char>> &image, int start, int end, bool is_row) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (isAllZero(mid, is_row, image)) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }

    bool isAllZero(int pos, bool is_row, vector<vector<char>> &image) {
        if (is_row) {
            for (int j = 0; j < image[0].size(); ++j) {
                if (image[pos][j] == '1')
                    return false;
            }
        } else {
            for (int i = 0; i < image.size(); ++i) {
                if (image[i][pos] == '1')
                    return false;
            }
        }
        return true;
    }
};

class Solution3 {
public:
    
    int minArea(vector<vector<char>> &image, int x, int y) {

        int n = image.size();
        int m = image[0].size();
    
        int x_min = findFirstNotAllZero(image, 0, x, &Solution3::isRowZero);
        int x_max = findLastNotAllZero(image, x, n - 1, &Solution3::isRowZero);
        int y_min = findFirstNotAllZero(image, 0, y, &Solution3::isColZero);
        int y_max = findLastNotAllZero(image, y, m - 1, &Solution3::isColZero);
        
        return (1 + x_max - x_min) *  (1 + y_max - y_min);
        return 0;
    }

private:
    
    typedef bool (*myFunc) (int, vector<vector<char>>& );

    int findFirstNotAllZero(vector<vector<char>> &image, int start, int end, myFunc check) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, image)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int findLastNotAllZero(vector<vector<char>> &image, int start, int end, myFunc check) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (check(mid, image)) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }

    static bool isRowZero(int pos, vector<vector<char>> &image) {
        for (int j = 0; j < image[0].size(); ++j) {
            if (image[pos][j] == '1')
                return false;
        }
        return true;
    }

    static bool isColZero(int pos, vector<vector<char>> &image) {
        for (int i = 0; i < image.size(); ++i) {
            if (image[i][pos] == '1')
                return false;
        }
        return true;
    }
};


class Solution {
public:
    
    int minArea(vector<vector<char>> &image, int x, int y) {

        int n = image.size();
        int m = image[0].size();
        
        
        int x_min = findFirstNotAllZero(image, 0, x, &Solution::isRowZero);
        int x_max = findLastNotAllZero(image, x, n - 1, &Solution::isRowZero);
        int y_min = findFirstNotAllZero(image, 0, y, &Solution::isColZero);
        int y_max = findLastNotAllZero(image, y, m - 1, &Solution::isColZero);
        
        return (1 + x_max - x_min) *  (1 + y_max - y_min);
        return 0;
    }

private:
    
    typedef bool (Solution::*myFunc) (int, vector<vector<char>>& );

    int findFirstNotAllZero(vector<vector<char>> &image, int start, int end, myFunc check) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((this->*check)(mid, image)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int findLastNotAllZero(vector<vector<char>> &image, int start, int end, myFunc check) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if ((this->*check)(mid, image)) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }

    bool isRowZero(int pos, vector<vector<char>> &image) {
        for (int j = 0; j < image[0].size(); ++j) {
            if (image[pos][j] == '1')
                return false;
        }
        return true;
    }

    bool isColZero(int pos, vector<vector<char>> &image) {
        for (int i = 0; i < image.size(); ++i) {
            if (image[i][pos] == '1')
                return false;
        }
        return true;
    }
};