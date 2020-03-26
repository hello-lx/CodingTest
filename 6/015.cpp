#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
   vector<vector<int>> permute(vector<int> &nums) {
       // write your code here
       vector<vector<int>> bak;  
       int n = nums.size() ;  
       if(n == 0) {
           bak.push_back(nums);
           return bak;
       }
       sort(nums.begin(),nums.end());  
       conv(nums,bak,0);  
       return bak;
    }
    
   void conv(vector<int>& nums,vector<vector<int>>& bak,int start){  
       if(nums.size() == start){  
           bak.push_back(nums);  
           return;  
       }  
       for(int i = start; i < nums.size(); i++){ 
           swap(nums[start],nums[i]);  
           conv(nums,bak,start + 1);  
           swap(nums[start],nums[i]); 
       }  
   }    
};
