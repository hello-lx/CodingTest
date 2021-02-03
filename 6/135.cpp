/*
public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // write your code here
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        
        dfs(candidates, target, new ArrayList<Integer>(), res, 0);
        
        return res;
    }
    
    private void dfs(int[] candidates, int target, List<Integer> list, List<List<Integer>> res, int index){
        if(target < 0)
            return;
        if(target == 0){
            res.add(new ArrayList<Integer>(list));
            return;
        }
        
        for(int i=index; i<candidates.length; i++){
            if(i != index && candidates[i] == candidates[i-1])
                continue;
            
            list.add(candidates[i]);
            dfs(candidates, target-candidates[i], list, res, i);
            list.remove(list.size()-1);
        }
    }
}
*/


class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    set<vector<int>> myset;
    vector<vector<int>> combinationSum(vector<int> &nums, int target) 
    {
        // write your code here
        vector<vector<int>> ret;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(ret, tmp, nums, 0,target);
        return ret;
    }
    
    void backtrack(vector<vector<int>>& ret, vector<int> &tempList, vector<int>& nums, int start,int target)
    {
        //ret.push_back(tempList);
        if(target < 0)
            return;
        else if(target == 0)
        {
            if(myset.find(tempList) == myset.end())
            {
                myset.insert(tempList);
                ret.push_back(tempList);
            }
        }
        else
        {
            for(int i = start; i < nums.size(); i++)
            {
                tempList.push_back(nums[i]);
                backtrack(ret, tempList, nums, i, target-nums[i]);
                tempList.erase(tempList.begin() + tempList.size() - 1);
            }
        }
        
    }
};