#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int>dp(nums.size()+1, 0);
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2; i<=nums.size(); i++){
            int temp1=i-1, temp2=0;
            for(int j=0; j<i-1; j++){
                if(nums[j]<nums[i-1])
                    temp1=dp[temp1+1]>dp[j+1]?temp1:j;
                if(nums[j]==nums[i-1])
                    temp2=dp[temp2+1]>dp[j+1]?temp2:j;
            }
            
            if(temp1!=(i-1) && temp2!=0)
                dp[i]=dp[temp2+2]>dp[temp1+1]+1?dp[temp2+1]:dp[temp1+1]+1;
            else if(temp1!=(i-1))
                dp[i]=dp[temp1+1]+1;
            else if(temp2!=0)
                dp[i]=dp[temp2+1];
            else
                dp[i]=1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
