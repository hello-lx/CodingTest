#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
using namespace std;

#define INT_MAX 99999999999999999999;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }
        unordered_map<int, int> maps;
        maps[0] = -1;
        vector<int> sums;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums.push_back(sum);
            if (maps.find(sum) != maps.end()) {
                res.push_back(maps[sum] + 1);
                res.push_back(i);
                return res;
            } else {
                maps[sum] = i;
            }
        }
        sort(sums.begin(), sums.end());
        int i1, i2;
        int min_diff = INT_MAX;
        res.push_back(0);
        res.push_back(0);
        for (int i = 0; i < sums.size() - 1; i++) {
            int diff = abs(sums[i + 1] - sums[i]);
            if (diff < min_diff) {
                min_diff = diff;
                res[0] = min(maps[sums[i]], maps[sums[i + 1]]) + 1;
                res[1] = max(maps[sums[i]], maps[sums[i + 1]]);
            }
        }
        
        return res;
    }
};
