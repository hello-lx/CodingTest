#include <vector>
using namespace std;
#define INT_MIN -999999

class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        // write your code here
        int n = matrix.size();
        if(n==0 || matrix[0].size()==0) return 0;
        vector<vector<int>> m = matrix;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+m[i-1][j-1];
        
        int max = INT_MIN;
        for(int i1=1; i1<=n; i1++)
            for(int i2=i1; i2<=n; i2++){
                int sum = 0;
                for(int j=1; j<=n; j++){
                    int temp = dp[i2][j]-dp[i1-1][j]-dp[i2][j-1]+dp[i1-1][j-1];
                    if(sum > 0)
                        sum += temp;
                    else
                        sum = temp;
                    if(sum > max)
                        max = sum;
                }
            }
        
        return max;
    }
};
