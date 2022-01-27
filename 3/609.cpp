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

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // write your code here
        
        int res = 0;
        int begin = 0;
        int end = nums.size() - 1;
        
        if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        while(begin < end)
        {
            if(nums[begin] + nums[end] <= target)
            {
                res += (end - begin); // 注意这里
                ++begin;
            }
            else
            {
                --end;
            }
        }
    
        return res;
    }
};
