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
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        int l=0;
        int h=nums.size()-1;
        int mid=0;
        while(mid<=h)
        {
            switch(nums[mid])
            {
                case 0:{
                    swap(nums[mid],nums[l]);
                    l++,mid++;
                    break;
                }
                case 1:
                {
                    mid++;
                    break;
                }
                case 2:
                {
                    swap(nums[mid],nums[h]);
                    h--;
                    break;
                }
            }
        }
    }
};
