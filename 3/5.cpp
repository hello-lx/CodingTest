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
     * @param k: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int k, vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};