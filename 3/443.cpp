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


class Solution 
{

public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) 
    { 
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = 0, l = 0, r = n - 1;
        while (l < r) 
        {
            if (nums[l] + nums[r] <= target)   // 若l指向元素与r指向元素的和不大于target
            {
                l++;
            } 
            else  // 否则，nums[l]可以与nums[l + 1 : r + 1]这r - l个元素配对    
            {
                result += r - l;
                r--;
            }
        }

        return result;
    }
};
