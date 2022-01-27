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
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        if(nums.size() <= k)
        {
            if(nums.size() == 0) return {};
            int s = 0;
            for(int i=0; i<nums.size(); i++)
                s += nums[i];
            return {s};
        }
        
        vector<int> res;
        for(int i=0; i<nums.size() - k + 1; i++)
        {
            int s = 0;
            for(int j=i; j<i+k; j++) s += nums[j];
            res.push_back(s);
        }
        return res;
    }
};
