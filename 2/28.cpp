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
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        int rows=matrix.size(), cols=matrix[0].size();
        int l=0, r = rows*cols-1;
        while(l + 1 < r)
        {
            int mid = (l + r) / 2;
            int row = mid / cols, col = mid % cols;
            
            if(matrix[row][col] < target) l = mid;
            else r = mid;
        }
        
        if(matrix[l/cols][l%cols] == target) return true;
        if(matrix[r/cols][r%cols] == target) return true;

        return false;
    }
};
