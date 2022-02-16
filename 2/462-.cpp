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
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) 
	{
		int ind = bs(A, target, 0, A.size() - 1);
		if (ind == -1) return 0;
		int ans = 1;
		for (int i = ind + 1; i < A.size() && A[i] == target; ++i) ++ans;
		for (int i = ind - 1; i >= 0 && A[i] == target; --i) ++ans;
		return ans;
    }
    
    int bs(vector<int> &A, int target, int l, int r)
	{
		if (l > r) return -1;
		int mid = l + (r - l) / 2;
		if (A[mid] == target) return mid;
		if (A[mid] > target) return bs(A, target, l, mid - 1);
		return bs(A, target, mid + 1, r);
	}
};
