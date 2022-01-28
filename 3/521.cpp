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
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1;
        }
        int left=0,right=1;
        sort(nums.begin(),nums.end());
        while(right<nums.size()){
            if(nums[right]!=nums[left]){
                left++;
                nums[left]=nums[right];
            }
            right++;
        }
        return left+1;
    }
};
