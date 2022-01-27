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
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [num1, num2] (num1 < num2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        if (nums.empty() || nums.size() < 2) {
            return {-1, -1};
        }
        
        // target 要取絕對值
        target = abs(target);
        int j = 1;
        for (int i = 0; i < nums.size(); i++) {
            // j 一定要在 i 的右邊，避免 i == j 的情形
            j = max(j, i + 1);
            
            while (j < nums.size() && nums[j] - nums[i] < target) {
                j++;
            }
            if (j == nums.size()) {
                break;
            }
            if (nums[j] - nums[i] == target) {
                return {nums[i], nums[j]};
            }
        }
        return {-1, -1};
    }
};