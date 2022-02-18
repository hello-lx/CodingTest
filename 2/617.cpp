#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INT_MIN -99999999999
#define INT_MAX 99999999999

/*
算法：二分答案
本题看到以后先想到暴力，即枚举所有可能子数组，时间复杂度O(N^2)会超时，于是我们考虑更低复杂度的做法，
是否有时间复杂度O(NlogN)O(NlogN)级别的做法呢？我们考虑二分答案来解决问题。

算法思路
我们考虑二分平均值，那么我们需要一个check函数，能在O(N)O(N)复杂度内判断是否存在一个子数组的平均值
大于等于我们二分出来的平均值

对于一个平均数ave，我们先将nums数组每个数减去ave，那么只要存在一个长度大于k的子数组和大于等于0，就说明
平均数ave可行，这可以在O(N)O(N)时间内完成

代码思路
1.设置二分的左右边界分别为数组中的最小值和最大值

2.判断平均值mid是否可行，若可行则说明答案大于等于mid，那么左边界等于mid，否则说明答案小于mid，右边界等于mid
如何判断平均值mid是否可行：
    1.将nums数组每个数减去mid
    2.求nums数组的前缀和数组pre
    3.设置指针index等于k
    4.那么在nums[0:index]中，长度大于k的子数组，区间和最大为pre[index - 1] - min{pre[0 : index - k]}
    5.将index不断右移直到指向数组末端，若中间区间和最大值大于等于0，check函数直接返回True，结束后还为返回值
      则返回False

3.不断重复 2 直到 left + 1e-5 == right 退出
4.返回左边界


复杂度分析
NN表示nums数组长度，max\_numsmax_nums和min\_numsmin_nums分别表示数组中最大值和最小值

空间复杂度：O(1)O(1)
实际处理时不需要记录下整个前缀和数组，只需记录当前的前缀和和左侧最小的前缀和
时间复杂度：O(Nlog(max\_nums - min\_nums))O(Nlog(max_nums−min_nums))
*/

class Solution {

public:

    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */

	bool check(vector<int> &nums, int k, double avg) {
        //rightSum表示当前指向位置的前缀和
        //leftSum表示当前指向位置左侧k个位置的前缀和
        //minLeftSum表示左侧最小的前缀和
        double rightSum = 0, leftSum = 0, minLeftSum = 0;
        for (int i = 0; i < k; i++) {
            rightSum += nums[i] - avg;
        }

        for (int i = k; i <= nums.size(); i++) 
        {
            if (rightSum - minLeftSum >= 0) {
                return true;
            }
    
            if (i < nums.size()) {
                rightSum += double(nums[i]) - avg;
                leftSum += double(nums[i - k]) - avg;
                minLeftSum = min(minLeftSum, leftSum);
            }
        }

        return false;
    } 

    double maxAverage(vector<int> &nums, int k) {
        double left, right, mid;
        //设置二分的左右边界分别为数组中的最小值和最大值
        left = right = double(nums[0]);
        for (int i = 0; i < nums.size(); i++) 
        {
            left = min(double(nums[i]), left);
            right = max(double(nums[i]), right);
        }

        while (left + 1e-5 < right) {
            mid = left + (right - left) / 2;
            //判断平均值mid是否可行
            //若可行则说明答案大于等于mid，那么左边界等于mid
            //否则说明答案小于mid，右边界等于mid
            if (check(nums, k, mid)) {
                left = mid;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};
