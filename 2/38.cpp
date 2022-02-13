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
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        unsigned int cnt=0, cols=matrix[0].size(), rows=matrix.size();
        int row=rows-1, col=0;
        while(row >= 0 and col < cols)
        {
            if(matrix[row][col] == target)
            {
                cnt++;
                col++;
            }
            if(matrix[row][col] < target) col++;
            else row--;
        }
        
        return cnt;
    }
};
