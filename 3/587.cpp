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
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        // write your code here
        if(nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;
        set<int> diff;
        while(l < r)
        {
            int sum = nums[l] + nums[r];
            if(sum == target)
            {
                diff.insert(nums[r]);
                l++;
                r--;
            }
            else if(sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return diff.size();
    }
};


int main()
{
    vector<int> data = {1,1,2,45,46,46};
    int target = 47;
    Solution s;
    cout << "sum: " << s.twoSum6(data, target) << endl;

    return 0;
}