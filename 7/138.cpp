#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
using namespace std;


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        for (int i = 0; i < nums.size(); i++) {
            int res = 0;
            for (int j = i; j < nums.size(); j++) {
                res += nums[j];
                if (res == 0) {
                    return vector<int> {i,j};
                }
            }
        }
        return {};
    }
};
