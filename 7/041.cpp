/*
class Solution:
    """
    @param nums: A list of integers
    @return: A integer indicate the sum of max subarray
    """
    def maxSubArray(self, nums):
        # write your code here
        cur = -float('inf')
        maxValue = -float('inf')
        for i in range(len(nums)):
            # cur描述了以当前节点为末节点的最大连续子串和
            cur = max(cur + nums[i], nums[i])
            maxValue = max(cur, maxValue)
        return maxValue

*/

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        int cur = -99999999;
        int maxValue = -99999999;
        for(int i=0; i<nums.size(); i++){
            cur = max(cur+nums[i], nums[i]);
            maxValue = max(cur, maxValue);
        }
        
        return maxValue;
    }
};
