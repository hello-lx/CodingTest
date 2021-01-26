#include <vector>
#include <queue>
using namespace std;

// blog: https://blog.csdn.net/cpongo3/article/details/89708994
struct Point
{
    int x, y;
    Point():x(0), y(0){}
    Point(int a, int b): x(a), y(b){}
};

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path
     */
    // BFS
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        vector<vector<int>> step = {{2,1},{1,2},{-2,1},{1,-2},{2,-1},{-1,2},{-1,-2},{-2,-1}};
        int n = grid.size(), m = grid[0].size(), res=0;
        queue<Point> q;
        q.push(source);
        grid[source.x][source.y] = true;
        while(!q.empty())
        {
            int N = q.size();
            res++;
            while(N > 0)
            {
                int col = q.front().x, row = q.front().y;
                N--;
                q.pop();
                if(col == destination.x && row == destination.y)
                    return res-1;
                for(int i=0; i<step.size(); i++)
                {
                    int newX=col+step[i][0], newY=row+step[i][1];
                    q.push(Point(newX, newY));
                    grid[newX][newY] = true;
                }
            }
        }

        return -1;
    }
};


int main(int argc, char** argv)
{
    
    return 0;
}