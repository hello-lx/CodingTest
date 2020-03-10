#include <algorithm>
#include <vector>
using namespace std;

bool mycmp(pair<int, int>& A, pair<int, int>& B)
{
    // first: min -> max
    if(A.first < B.first)
    {
        return true;
    }
    else if(A.first > B.first)
    {
        return false;
    }
    // second: max -> min
    if(A.second > B.second)
    {
        return true;
    }
    
    return false;
}     

class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
     
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // write your code here
        sort(envelopes.begin(), envelopes.end(), mycmp);
        //for_each(envelopes.begin(), envelopes.end(), myprint);
        vector<int> nums;
        for(int i = 0; i < envelopes.size(); i++)
        {
            nums.push_back(envelopes[i].second);
        }
        
        return longestIncreasingSubsequence(nums);
    }
    
    int longestIncreasingSubsequence(vector<int> &nums) 
    {
        // write your code here
        int size = nums.size();
        int res = 0;
        int top[size];
        int piles = 0;
        for(int i = 0; i < size; i++)
        {
            int poker = nums[i];
            int left = 0;
            int right = piles;
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(top[mid] >= poker)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            if(left == piles)
                piles++;
            top[left] = poker;
        }
        return piles;
    }
    
};
