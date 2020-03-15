#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        // write your code here
        vector<vector<int>> res;
        if(matrix.empty())  return res;
        res = vector<vector<int>>(2, vector<int>(2, 0));
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> sum(row+1, vector<int>(col+1, 0));
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++){
                sum[i+1][j+1] = matrix[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
            }
        
        for(int i1=0; i1<row; i1++){
            for(int i2=i1+1; i2<row+1; i2++){
                map<int, int> m;
                for(int j=0; j<col+1; j++){
                    int diff = sum[i2][j] - sum[i1][j];
                    if(m.find(diff) != m.end()){
                        res[0] = {i1, m[diff]};
                        res[1] = {i2-1, j-1};
                        return res;
                    }else{
                        m[diff] = j;
                    }
                }
            }
        }
        
        return res;
    }
    
};
