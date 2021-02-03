class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &nums) {
        // write your code here
        vector<vector<string>> ret;
        vector<string> tmp;
        
        backtrack(ret, tmp, nums, 0);
        return ret;
    }
    
    void backtrack(vector<vector<string>>& ret, vector<string> &tempList, string& nums, int start)
    {
        if(start == nums.size())
        {
            ret.push_back(tempList);
        }
        for(int i = start; i < nums.size(); i++)
        {
            string tmp = nums.substr(start, i-start+1);
            if(tmp == ""  || !ishuiwen(tmp))
                continue;
            tempList.push_back(tmp);
            backtrack(ret, tempList, nums, i+1);
            tempList.erase(tempList.begin() + tempList.size() - 1);            
        }
    }
    bool ishuiwen(string& nums)
    {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            if(nums[left] != nums[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};