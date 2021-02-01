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