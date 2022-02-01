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
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) 
    {
        // write your code here
        
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            while (left <= right && nums[left] < k) left++;
            while (left <= right && nums[right] >= k) right--;

            if (left < right) {
                swap(&nums[left], &nums[right]);
                left++;
                right--;
            }
        }

        return left;
    }

    void swap(int *left, int *right) {
        int tmp = *left;
        *left = *right;
        *right = tmp;
    }
};
