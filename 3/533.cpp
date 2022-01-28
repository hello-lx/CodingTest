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
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // write your code here
        if(nums.size()<2) return -1;
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        int left=0, right=nums.size()-1;
        while(left<right)
        {
            int sum=nums[left]+nums[right];
            if(sum==target)
                return 0;
            else if(sum>target)
            {
                diff=min(diff,abs(target-sum));
                right--;
            }
            else
            {
                diff=min(diff,abs(target-sum));
                left++;
            }  
        }
        
        return diff;
    }
};
