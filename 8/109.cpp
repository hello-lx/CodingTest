#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        
        int height = triangle.size();
        
        for(int i=height-1; i>=0; i--)
            for(int j=0; j<triangle[i].size()-1; j++){
                triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
            }
        
        return triangle[0][0];
    }
};
