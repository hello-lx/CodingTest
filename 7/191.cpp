#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        // write your code here
        if(nums.empty()) return 0;
        int ret, pos, neg;
        pos = nums[0];
        neg = nums[0];
        ret = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int temp = pos;
            //最大值乘以负数有可能变为最小值，最小值乘以负数有可能变为最大值
            pos = max(nums[i], max(pos * nums[i], neg * nums[i]));//在不断的计算最大值
            neg = min(nums[i], min(temp * nums[i], neg * nums[i]));//在不断的计算最小值
            ret = max(pos, ret);
        }
        return ret;
    }
};
