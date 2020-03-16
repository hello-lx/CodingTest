/*
构建相应的数组ForMax[i]表示从nums[0]到nums[i]的子数组和的最大值，ForMin[i]表示从nums[0]到nums[i]的
子数组和的最小值，RevMax[i]表示从nums[i]到nums[len-1]的子数组和的最大值，RevMin[i]表示从nums[i]到
nums[len-1]的子数组和的最小值。最终的结果取ForMax[i] - RevMin[i + 1]与RevMax[j] - ForMin[j - 1]
的最大值
*/

#include <vector>
#include <algorithm>
#define INT_MIN -99999;
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        // write your code here
        if (nums.empty())
            return 0;
        int len = nums.size();
        //ForMax[i]表示从nums[0]到nums[i]的子数组和的最大值
        //ForMin[i]表示从nums[0]到nums[i]的子数组和的最小值
        //RevMax[i]表示从nums[i]到nums[len-1]的子数组和的最大值
        //RevMin[i]表示从nums[i]到nums[len-1]的子数组和的最小值
        vector<int> ForMax(len), ForMin(len), RevMax(len), RevMin(len);
        ForMax[0] = nums[0];
        ForMin[0] = nums[0];
        RevMax[len - 1] = nums[len - 1];
        RevMin[len - 1] = nums[len - 1];
        int res = INT_MIN;
        int Max = nums[0], Min = nums[0];
        int curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < len; ++i)
        {
            if (curMax>0)
                curMax += nums[i];
            else
                curMax = nums[i];
            if (curMax > Max)
                Max = curMax;
            ForMax[i] = Max;
            if (curMin < 0)
                curMin += nums[i];
            else
                curMin = nums[i];
            if (curMin < Min)
                Min = curMin;
            ForMin[i] = Min;
        }
        Max = nums.back(), Min = nums.back();
        curMax = Max, curMin = Min;
        for (int i = len - 2; i >= 0; --i)
        {
            if (curMax>0)
                curMax += nums[i];
            else
                curMax = nums[i];
            if (curMax > Max)
                Max = curMax;
            RevMax[i] = Max;
            if (curMin < 0)
                curMin += nums[i];
            else
                curMin = nums[i];
            if (curMin < Min)
                Min = curMin;
            RevMin[i] = Min;
        }
        //计算ForMax[i] - RevMin[i + 1]
        for (int i = 0; i < len - 1; ++i)
        {
            res = max(res, ForMax[i] - RevMin[i + 1]);
        }
        //计算RevMax[i] - ForMin[i - 1]
        for (int i = len - 1; i > 0; --i)
        {
            res = max(res, RevMax[i] - ForMin[i - 1]);
        }
        return res;
    }
};
