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
     * @param A: an integer array sorted in ascending order
     * @param target: An integer
     * @return: an integer
     */
    int closestNumber(vector<int> &A, int target) {
        // write your code here
        int left = 0, right = A.size() - 1;
        if (right < 0) {
            return -1;
        }
        
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        if (abs(A[left] - target) < abs(A[right] - target)) {
            return left;
        }
        return right;
    }
};
