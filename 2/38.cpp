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
        unsigned int cnt=0;//因为size()函数返回的都是unsigned值，所以用unsigned比较好，当然不用也可以啦~
        unsigned int col = matrix[0].size();
        unsigned int row = matrix.size();
        int i = row-1;
        int j = 0;
        while(i >= 0 and j < col) {
            if(matrix[i][j] == target) {
                cnt++;
                j++;
            }
            if(matrix[i][j] < target) {
                j++;
            }
            else {
                i--;
            }
        }
        return cnt;
    }
};
