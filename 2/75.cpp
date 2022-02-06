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
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        // write your code here
        int l = 0, r = A.size() - 1;
        while(l+1 < r)
        {
            int mid = (l + r) / 2;
            if(A[mid] < A[mid+1]) l = mid;
            else if(A[mid] < A[mid-1]) r = mid;
            else return mid;
        }

        return max(A[l], A[r]);
    }
};