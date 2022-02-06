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
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.empty()) return -1;

        int l=0, r=A.size()-1;
        while(l+1 < r)
        {
            int mid = l + (r-l)/2;
            if(A[mid] == target) return mid;

            if(A[mid] > A[l])
            {
                if(target >= A[l] && target < A[mid]) r = mid;
                else l = mid;
            }
            else if(A[mid] < A[l])
            {
                if(target < A[l] && target > A[mid]) l = mid;
                else r = mid;
            }
            else
            {
                l++;
            }
        }

        if(A[l] == target) return l;
        if(A[r] == target) return r;
        return -1;
    }
};
