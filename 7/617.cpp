#include<vector>
#include<iostream>
using namespace std;
#define INT_MAX 999999;
#define INT_MIN -999999;

class Solution {
public:
    /*
    * @param nums: an array with positive and negative numbers
    * @param k: an integer
    * @return: the maximum average
    */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        double l = INT_MAX;
        double r = INT_MIN;
        int len = nums.size();
        for (auto c : nums)
        {
            if (c < l)
                l = c;
            if (c>r)
                r = c;
        }
        vector<double> sum(len+1, 0);
        sum[0] = 0;
        while (r - l >= 1e-6)
        {
            double mid = (l + r) / 2.0;
            double min_pre = 0;
            bool check = false;
            for (int i = 1; i <= len; ++i)
            {
                sum[i] = sum[i - 1] + nums[i - 1] - mid;
                if (i >= k&&sum[i] - min_pre >= 0)
                {
                    check = true;
                    break;
                }
                if (i >= k)
                    min_pre = minVal(min_pre, sum[i - k + 1]);
            }
            if (check)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
    double minVal(double a, double b)
    {
        return a < b ? a : b;
    }
};
