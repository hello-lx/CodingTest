#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
     
    void merge(vector<int> &result, vector<int> L, int LSize, vector<int> R, int RSize)
    {
        // left id, right id, result id
        int Li=0, Ri=0, ri=0;  
        
        while(Li < LSize && Ri < RSize)
            result[ri++] = L[Li] < R[Ri] ? L[Li++] : R[Ri++];

        while(Li < LSize) 
            result[ri++] = L[Li++];
        while(Ri < RSize)
            result[ri++] = R[Ri++];
    }
    
    void mergeSort(vector<int> &data, int n)
    {
        if (n < 2) return;
        int mid = data.size() / 2;
        vector<int> L(mid, 0), R(n-mid, 0);
        
        for(int i=0; i<mid; i++) L[i] = data[i];
        for(int i=mid; i<n; i++) R[i-mid] = data[i];
        mergeSort(L, mid);
        mergeSort(R, n-mid);
        merge(data, L, mid, R, n-mid);
    }
    
    void process(int start, vector<int> &candidates, int target, vector<int> &result)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            results_set.insert(result);
        }
        else
        {
            for(int i=start; i<candidates.size(); i++)
            {
                result.push_back(candidates[i]);
                process(i+1, candidates, target - candidates[i], result);
                result.erase(result.begin() + result.size() - 1);
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        
        if(num.size() == 0 || target < 0)
            return results;
        
        mergeSort(num, num.size());
        
        vector<int>  result;
        process(0, num, target, result);
        for(auto it=results_set.begin(); it!=results_set.end(); it++)
            results.push_back(*it);
        return results;
    }
    
    set<vector<int>> results_set;
    vector<vector<int>> results;
};