#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // write your code here
        vector<int> res;
        if (nums.empty())
            return res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        map<int, vector<int>> m;//存放元素与其对应的整除子集
        vector<int> num;
        for (int i = 0; i < len; ++i)
        {
            num.clear();
            for (int j = i - 1; j >= 0; --j)//遍历i之前的元素
            {
                if (nums[i] % nums[j] == 0 && m[nums[j]].size()>num.size())//找到nums[i]可以整除且最长的整除数组
                {
                    num = m[nums[j]];
                }               
            }
            num.push_back(nums[i]);//nums[i]加到此数组后面,当i==1或者前面没有可以整除的数字，就直接加上自身
            m[nums[i]] = num;//更新map
        }
        
        for (auto c : m)    //获得最长的整除子集
        {
            if (c.second.size() > res.size())
                res = c.second;
        }
        
        return res;
    }
};
