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
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        if(nums.empty()) return -1;

        int l = 0, r = nums.size() - 1;
        while(l + 1 < r)
        {
            int mid = (l+r)/2;
            if(nums[mid] < target) l = mid;
            else if(nums[mid] > target) r = mid;
            else
            {
                while(nums[mid-1] == target) mid--;
                return mid;
            }
        }
        
        if(nums[l] == target) return l;
        if(nums[r] == target) return r;

        return -1;
    }
};

int main()
{
    return 0;
}
