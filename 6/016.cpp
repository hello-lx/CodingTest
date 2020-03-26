#include <vector>
using namespace std;

    
class Solution {
public:
    /**
        * @param nums: A list of integers.
        * @return: A list of unique permutations.
        */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        
        vector<vector<int>> res;
        
        help(res, nums, 0);
            
        return res;
            
    }
    
    void help(vector<vector<int>> &res, vector<int>&num,int p){
        if (p ==num.size()){
            res.push_back(num);
        } else {
            for (int i = p; i<num.size(); i++) {
                if(contain(num,p,i))
                    continue;
                swap(num[i],num[p]);
                help(res, num, p+1);
                swap(num[i],num[p]);
            }
        }
    }
    
    bool contain(vector<int>& num, int p, int i){
        if (i>p) {
            for (int j = p; j<i; j++){
                if (num[j]==num[i])
                    return true;
            }
        }
        return false;
    }
};
