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
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> ans;
        for(int i=0; i<A.size(); i++)
            if(A[i] == target) ans.push_back(i);
        
        if(ans.size() == 0) return {-1, -1};
        if(ans.size() == 1) return {ans[0], ans[0]};
        return {ans[0], ans[ans.size()-1]};
    }
};