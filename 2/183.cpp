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
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        int maxLen = getMaxLen(L);
        
        int left = 1, right = maxLen;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (isValidLen(mid, L, k)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        if (isValidLen(right, L, k)) return right;
        if (isValidLen(left, L, k)) return left;
        return 0;
    }
    
    bool isValidLen(int target, vector<int> &L, int k) {
        int totalNum = 0;
        for (int len : L) {
            totalNum += len / target;
        }
        return totalNum >= k;
    }
    
    int getMaxLen(vector<int> &L) 
    {
        int maxLen = INT_MIN;
        for (int len : L) {
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
