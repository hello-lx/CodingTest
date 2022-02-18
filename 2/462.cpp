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

    int totalOccurrence2(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0){
            return 0;
        }

        int first, last;
		
        //寻找第一次出现的位置
        int left = 0, right = A.size() - 1;
        while (left + 1 < right){
            int mid = left + (right - left) / 2;
            if (A[mid] >= target){
                right = mid;
            }else{
                left = mid;
            }
        }

        if (A[left] == target){
            first = left;
        }else if (A[right] == target){
            first = right;
        //若找不到直接返回0
        }else{
            return 0;
        }

        //寻找最后一次出现的位置
        left = 0, right = A.size() - 1;
        while (left + 1 < right){
            int mid = left + (right - left) / 2;
            if (A[mid] <= target){
                left = mid;
            }else{
                right = mid;
            }
        }

        //注意与first的判断顺序有别，要先判右侧的
        if (A[right] == target){
            last = right;
        }else if (A[left] == target){
            last = left;
        }

        return last - first + 1;
    }


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
