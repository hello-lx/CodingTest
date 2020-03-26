#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        int n = nums.size();
        if(n == 0) return res;
        
        for(int i=0; i<n; i++){
            int s = res.size();
            for(int j=0; j<s; j++){
                vector<int> arr = res[j];
                arr.push_back(nums[i]);
                sort(arr.begin(), arr.end());
                res.push_back(arr);
            }
        }
        
        return res;
    }
        
};


/* Java
public class Solution {

//      * @param nums: A set of numbers
//      * @return: A list of lists

    public List<List<Integer>> subsets(int[] nums) {
        // write your code here
        List<List<Integer>>  aList = new ArrayList<List<Integer>>();
        aList.add(new ArrayList<Integer>());
        for (int num : nums){
            int size =  aList.size();
            for(int i =  0; i < size; i++){
                List<Integer> temp = new ArrayList<>(aList.get(i));
                temp.add(num);
                Collections.sort(temp);
                aList.add(temp);
            }
        }
        return aList;
    }
}
*/
