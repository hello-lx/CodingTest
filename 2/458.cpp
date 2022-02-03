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
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        int left=0;
        int right=nums.size()-1;
        int ans=-1;
        while(right>=left)  
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
            {
                  ans=mid;
                  left=mid+1;
            }
            else if(nums[mid]>target)
                right=mid-1;
            else
                 left=mid+1;
        }
        return ans;
    }
};
