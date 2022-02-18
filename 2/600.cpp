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


class Solution2 {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int xx, int yy) {
        // write your code here
        int n = image.size();
        int m = image[0].size();

        queue<int> q;
        unordered_set<int> visited;
        q.push(xx * m + yy);
        visited.insert(xx * m + yy);

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int x_min = n;
        int x_max = 0;
        int y_min = m;
        int y_max = 0;
  
        while (!q.empty()) {
            int x = q.front() / m;
            int y = q.front() % m;
            q.pop();

            x_min = min(x_min, x);
            x_max = max(x_max, x);
            y_min = min(y_min, y);
            y_max = max(y_max, y);

            for (int i = 0; i < 4; i++) 
            {
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m || image[x_][y_] == '0')
                    continue;
                int new_pos = x_ * m + y_;
                if (visited.count(new_pos))
                    continue;
                
                q.push(new_pos);
                visited.insert(new_pos);
            }
        }
        
        return (x_max - x_min + 1) * (y_max - y_min + 1);

    }
};


// bfs: time out
class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here

        if(image.size() == 0 || image[0].size() == 0) return 0;
        
        int rows=image.size(), cols=image[0].size();
        queue<pair<int, int>> Q;
        Q.push({x, y});
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[x][y] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int minX=x, maxX=x, minY=y, maxY=y;

        while(!Q.empty())
        {
            auto p = Q.front();
            Q.pop();
            
            visited[p.first][p.second] = true;
            minX = min(minX, p.first);
            maxX = max(maxX, p.first);
            minY = min(minY, p.second);
            maxY = max(maxY, p.second);
            
            for(int i=0; i<4; i++)
            {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if(nx>=0 && nx<rows && ny>=0 && ny<cols && !visited[nx][ny] && image[nx][ny] == '1')
                {
                    Q.push({nx, ny});
                }
            }
        }

        cout << minX << ' ' << maxX << ' ' << minY << ' ' << maxY << endl;
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
}; 