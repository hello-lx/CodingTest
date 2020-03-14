
/*  https://blog.csdn.net/weixin_44424668/article/details/104017294
 * 
public class Solution {

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n + 1][5 + 1];

        //初始化
        dp[0][1] = 0;
        for (int i = 2; i <= 5; i++) {
            dp[0][i] = Integer.MIN_VALUE;
        }

        //遍历n天的价格
        for (int i = 1; i <= n; i++) {

            //阶段1、3、5，手里不持有股票
            for (int j = 1; j <= 5; j += 2) {
                dp[i][j] = dp[i - 1][j];
                //肯定是第一个阶段以后的，所以j>1,且上一个阶段dp[i - 1][j - 1]不能为无穷小
                if (i - 2 >= 0 && j > 1 && dp[i - 1][j - 1] != Integer.MIN_VALUE) {
                    //继续不持有，或者昨天持有，今天卖掉变为不持有
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                }
            }

            //阶段2、4，手里持有股票
            for (int j = 2; j <= 4; j += 2) {
                //从上一个不持有的阶段变为持有
                dp[i][j] = dp[i - 1][j - 1];
                //不用判断j，从阶段2开始，且昨天持有时dp[i - 1][j]不能为无穷小
                if (i - 2 >= 0 && dp[i - 1][j] != Integer.MIN_VALUE) {
                    //继续持有，继续获利，或是今天才买入
                    dp[i][j] = Math.max(dp[i - 1][j] + prices[i - 1] - prices[i - 2], dp[i - 1][j - 1]);
                }
            }
        }
        return Math.max(dp[n][1], Math.max(dp[n][3], dp[n][5]));
    }
}
 * 
 */

#include <algorithm>
#include <vector>
using namespace std;
#define INT_MIN -999999999;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if(n == 0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(5+1, 0));
        dp[0][1] = 0;
        for(int i=2; i<=5; i++)
            dp[0][i] = INT_MIN;
            
        for(int i=1; i<= n; i++){
            
            // 1/3/5  昨天无股票并保持无股票状态 或 昨天有股票今天卖出 
            for(int j=1; j<=5; j+=2){
                dp[i][j] = dp[i-1][j];
                if(i-2>=0 && j>1 && dp[i-1][j-1] != INT_MIN)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+prices[i-1]-prices[i-2]);
            }
            
            // 2/4  昨天有股票并保持有股票状态（获利和亏损都有可能，要加上） 或 昨天没股票今天买入 
            for(int j=2; j<=4; j+=2){
                dp[i][j] = dp[i-1][j-1];
                if(i-2 >= 0 && dp[i-1][j] != INT_MIN)
                    dp[i][j] = max(dp[i-1][j]+prices[i-1]-prices[i-2], dp[i-1][j-1]);
            }
        }
        
        return max(dp[n][1], max(dp[n][3], dp[n][5]));
    }
};
