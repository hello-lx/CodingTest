/* Python3

class Solution:
    """
    @param nums: A set of numbers.
    @return: A list of lists. All valid subsets.
    """
    def subsetsWithDup(self, nums):
        # write your code here
        self.results = []
        self.search(sorted(nums), [], 0)
        return self.results
 
    def search(self, nums, S, index):
        self.results.append(S[:])
        
        for i in range(index, len(nums)):
            if i!=index and nums[i] == nums[i-1]:
                continue
            S.append(nums[i])
            self.search(nums, S, i+1)
            S.pop()

*/


/* Java
public class Solution {
//      * @param nums: A set of numbers.
//      * @return: A list of lists. All valid subsets.
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        ArrayList<List<Integer>> res=new ArrayList<List<Integer>>();
        ArrayList<Integer>list=new ArrayList<Integer>();
        if(nums==null ){
            return res;
        }
        res.add(list);
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            int size=res.size();
            for(int j=0;j<size;j++){
                List<Integer>temp=res.get(0);
                res.remove(0);
                ArrayList<Integer>temp2=new ArrayList<Integer>(temp);
                temp2.add(temp2.size(),nums[i]);
                if(!res.contains(temp2))
                    res.add(temp2);
                if(!res.contains(temp))
                    res.add(temp);
            }
        }
        return res;
    
    }
}
*/
