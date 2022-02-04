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
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        if(nums.empty()) return -1;
        
        int l=0, r=nums.size()-1;
        while(l+1 < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[r]) r = mid;
            else l = mid+1;
        }

        return min(nums[l], nums[r]);
    }
};
