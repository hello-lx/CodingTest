#include <vector>
using namespace std;
#define INT_MIN -999999


class NumMatrix {
public:
    vector<vector<int>> dp;
    vector<vector<int>> nums;
    NumMatrix(vector<vector<int>> matrix) {
         dp = matrix;
         nums = matrix;
        if(matrix.size() == 0)
            return;
        // vector<long long> tmp(matrix[0].size(), 0);
        // for(int i = 0; i < matrix.size(); i++)
        //     dp.push_back(tmp);
        // cout << matrix.size() << endl;
        // cout << matrix[0].size() << endl;
        // cout << " -- " << endl; 
        for(int i = 0; i < dp.size(); i++)
        {
            for(int j = 0; j < dp[i].size(); j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] =  matrix[i][j];
                }
                else if(i == 0)
                {
                    dp[i][j] = dp[i][j-1] + matrix[i][j];
                }
                else if(j == 0)
                {
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j]; 
                }
            }
           // dp.push_back(tmp);
        }
    }
    
    void update(int row, int col, int val) 
    {
        // for(int i = 0; i < dp.size(); i++)
        // {
        //     for(int j = 0; j < dp[i].size(); j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        int chazhi = val - nums[row][col];
        nums[row][col] = val;
        for(int i = row; i < dp.size(); i++)
        {
            for(int j = col; j < dp[i].size(); j++)
            {
                dp[i][j] = dp[i][j] + chazhi;
            }
        }
        // for(int i = 0; i < dp.size(); i++)
        // {
        //     for(int j = 0; j < dp[i].size(); j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = dp[row2][col2];
        int sum1 = INT_MIN;
        if(row1 - 1 >= 0)
            sum1 = dp[row1-1][col2];
        int sum2 = INT_MIN;
        if(col1 - 1 >= 0)
            sum2 = dp[row2][col1-1];
        int ret;
        if(sum1 != INT_MIN && sum2 != INT_MIN)
            ret = total - sum1 - sum2 + dp[row1-1][col1-1];
        else if(sum1 != INT_MIN)
        {
            ret = total - sum1;
        }
        else if(sum2 != INT_MIN)
        {
            ret = total - sum2;
        }
        else
        {
            ret = total;
        }
        // if(ret == -7)
        // {
        //     cout << row1 << " " << col1<<" " << row2 << " " << col2 << endl;
        // }
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */






/* my method (bug)
class NumMatrix {
private:
    vector<vector<int>> m;
    vector<vector<int>> sums;
    int rows, cols;
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix;
        rows = m.size();
        cols = m[0].size();
        sums = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        
        for(int i=1; i<=rows; i++)
            for(int j=1; j<=cols; j++){
                sums[i][j] = m[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
            }
    }
    
    void update(int row, int col, int val) {
        m[row][col] = val;
        for(int i=row; i<=rows; i++){
            for(int j=col; j<=cols; j++){
                sums[i][j] = m[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row2+1][col1]-sums[row1][col2+1]+sums[row1][col1];
    }
};
*/
