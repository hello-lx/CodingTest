#include <vector>
#include <iostream>
#include <map>
using namespace std;


/*
来一份三根指针的题解，left mid right：
首先就是 mid 和 right 要交错，然后是 left 和 right 要交错。
*/

/*
python: 
        if not nums:
            return 
        
        start, end = 0, len(nums) - 1
        while start <= end:
            while start <= end and nums[start] < low:
                start += 1
            while start <= end and nums[end] >= low:
                end -= 1
            if start <= end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1
        
        # the ending point will be like
        # end | | start
        # example: low = 2, high = 3
        # 1,1,4,3,2,3,4,2
        #   j i
        while start < len(nums) - 1 and nums[start] <= low:
            start += 1

        start, end = start,  len(nums) - 1
        while start <= end:
            while start <= end and nums[start] <= high:
                start += 1
            while start <= end and nums[end] > high:
                end -= 1
            if start <= end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1
*/

class Solution {
public:


    // c++ error: why?
    void partition2(vector<int> &nums, int low, int high) {
        
        if (nums.size() < 2) {
            return;
        }
        
        int left = 0, right = nums.size() - 1;
        
        while(left <= right)  // sort low numbers
        {
            while(left <= right && nums[left] < low)
                left++;
            while(left <= right && nums[right] >= low)
                right--;
            
            if(left <= right)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                
                left++;
                right--;
            }
        }

        // the ending point will be like
        // end | | start
        // example: low = 2, high = 3
        // 1,1,4,3,2,3,4,2
        //   j i
        if(left <= nums.size() - 1 && nums[left] <= low)
            left++;

        right = nums.size() - 1;

        
        while(left <= right)
        {
            while(left <= right && nums[left] <= high)
                left++;
            while(left <= right && nums[right] > high)
                right--;
            
            if(left <= right)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                
                left++;
                right--;
            }
        }
    }
};


