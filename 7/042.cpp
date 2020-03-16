/*
class Solution:
    """
    @param: nums: A list of integers
    @return: An integer denotes the sum of max two non-overlapping subarrays
    """
    def maxTwoSubArrays(self, nums):
        # write your code here
        dp_lift = [[0, 0] for i in range(len(nums))]
        dp_right = [[0, 0] for j in range(len(nums))]

        dp_lift[0][0] = nums[0]
        dp_lift[0][1] = nums[0]
        for i in range(1, len(nums)):
            dp_lift[i][0] = max(nums[i], nums[i] + dp_lift[i - 1][0])
            dp_lift[i][1] = max(dp_lift[i][0], dp_lift[i - 1][1])
        dp_right[-1][0] = nums[-1]
        dp_right[-1][1] = nums[-1]
        for i in reversed(range(0, len(nums) - 1)):
            dp_right[i][0] = max(nums[i], nums[i] + dp_right[i + 1][0])
            dp_right[i][1] = max(dp_right[i][0], dp_right[i + 1][1])
        result = -10000
        for i in range(0, len(dp_lift)-1):
            result = max(result, dp_lift[i][1] + dp_right[i+1][1])
        return result
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<vector<int>> dp_left = vector<vector<int>>(n, vector<int>(2, 0));
        vector<vector<int>> dp_right = vector<vector<int>>(n, vector<int>(2, 0));
        
        dp_left[0][0] = nums[0];
        dp_left[0][1] = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp_left[i][0] = max(nums[i], nums[i]+dp_left[i-1][0]);
            dp_left[i][1] = max(dp_left[i][0], dp_left[i-1][1]);
        }
        
        dp_right[n-1][0] = nums[n-1];
        dp_right[n-1][1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            dp_right[i][0] = max(nums[i], nums[i]+dp_right[i+1][0]);
            dp_right[i][1] = max(dp_right[i][0], dp_right[i+1][1]);
        }
        
        int result = -10000;
        for(int i=0; i<n-1; i++)
            result = max(result, dp_left[i][1] + dp_right[i+1][1]);
        return result;
    }
};

