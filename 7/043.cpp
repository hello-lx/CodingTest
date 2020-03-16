#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> &nums, int k) {
        // write your code here
        vector<vector<int> > dp(nums.size()+1,vector<int>(k+1,INT_MIN));
        for(int i=0;i<nums.size();i++)
            dp[i][0] = 0;
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=min(i,k);j++)
            {
                int endMax = 0;
                int mx = INT_MIN;
                for(int p = i;p>=j;p--)
                {
                    endMax = max(nums[p-1],nums[p-1]+endMax);
                    mx = max(mx,endMax);
                    dp[i][j] = max(dp[i][j],dp[p-1][j-1]+mx);
                }
            }
        }
        return dp[nums.size()][k];
    }
};
