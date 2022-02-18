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
     * @param k: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        if(nums.size()==0||nums.size()<n){
            return -1;
        }
        return quick_select(nums,n,0,nums.size()-1);
    }
    
    int quick_select(vector<int>& nums, int k, int start, int end){
        if(start==end){
            return nums[start];
        }
        int left=start;
        int right=end;
        int middle=nums[(start+end)/2];
        while(left<=right){
            while(left<=right && nums[left]>middle){
                left++;
            }
            while(left<=right && nums[right]<middle){
                right--;
            }
            if(left<=right){
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                left++;
                right--;
            }
        }
        if(k<=right-start+1){
            return quick_select(nums,k ,start,right);
        }
        if(k>left-start){
            return quick_select(nums,k-(left-start) ,left,end);
        }
        return nums[right+1];
    }
};