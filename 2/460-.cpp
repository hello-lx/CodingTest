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
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        int pos = lower_bound(A.begin(), A.end(), target) - A.begin(), i = pos - 1, j = pos;
        vector<int> ans;
        while (j - i - 1 < k) {
            if (i < 0 || j < A.size() && abs(A[j] - target) < abs(A[i] - target)) 
                ans.push_back(A[j++]);
            else 
                ans.push_back(A[i--]);
        }
        return ans;
    }
};
