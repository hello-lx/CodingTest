#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int i = nums.size() - 2;  
        while (i >= 0 && nums[i] >= nums[i + 1]) //从右往左，找出第一个左边小于右边的数A
        {  
            i--;  
        }  
        if (i < 0) 
        {  
            reverse(nums.begin(), nums.end() - 1);  
        }  
        else 
        {  
            int j = i + 2;  
            while (j < nums.size() && nums[j] > nums[i]) //从右往左，找出第一个大于A的数
            {  
                j++;  
            }  
            j--;  

            nums[i] ^= nums[j];  //采用异或运算实现两数交换
            nums[j] ^= nums[i];  
            nums[i] ^= nums[j];  
              
            reverse(nums.begin() + i + 1, nums.end() - 1);  //将A后面的数据从小到大排序,即翻转该部分数据
        }  
        return nums;
    }
    private:  
    void reverse(vector<int>::iterator i1, vector<int>::iterator i2) {  
        while (i1 < i2) 
        {  
            *i1 ^= *i2;  
            *i2 ^= *i1;  
            *i1 ^= *i2;  
       
            i1++;  
            i2--;  
        }  
    }
};
