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
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        int l = 0;
        int r = nums.size() -1;
        while(l < r){
            if(nums[l] + nums[r] == target){
                vector<int> indexs{l+1,r+1};
                return indexs;
            } else if(nums[l] + nums[r] > target){
                r--;
            } else{
                l++;
            }
        }
    }
};
