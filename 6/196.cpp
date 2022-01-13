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

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size(), i = 0;
        while (i<n) {
            while (nums[i]!=i && nums[i]<n) swap(nums[i], nums[nums[i]]);  
            ++i;
        }
        
        for (int i=0; i<n; ++i)
            if (nums[i]!=i) return i;
        
        return n;
    }
};




