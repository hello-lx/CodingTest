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


class TwoSum {
private:
    unordered_multiset<int> nums;
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        nums.insert(number);
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        for (auto it = nums.begin(); it != nums.end(); it++) {
            int count = (*it == value - *it) ? 2 : 1;
            if (nums.count(value - *it) >= count) {
                return true;
            }
        }

        return false;
    }
};