#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    long long permutationIndexII(vector<int> &A) {
        
        long long ans = 1;
        
        unordered_set<int> unset;
        
        for (int i = 0; i < A.size() - 1; ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] <= A[j] || unset.find(A[j]) != unset.end()) {
                    continue;
                }
                int save = A[j];
                unset.insert(save);
                A[j] = A[i];
                ans += findPermutations(i + 1, A);
                A[j] = save;
            }
            unset.clear();
        }
        
        return ans;
    }

    long long findPermutations (int start, vector<int> &A) {
        
        unordered_map<int, int> mapCount;
        
        for (int i = start; i < A.size(); ++i) {
            mapCount[A[i]]++;
        }
        
        return myDFS(mapCount);
    }
    
    long long myDFS (unordered_map<int, int> &mapCount) {
        
        if (mapCount.size() == 1) {
            return 1;
        }
        
        long long ret = 0;
        
        unordered_map<int, int>::iterator it;
        
        vector<int> temp;
        
        double hash = 0;

        for (it = mapCount.begin(); it != mapCount.end(); ++it) {
            temp.push_back(it->first);
            //根据出现次数算总体hashCode
            hash += pow(31, it->second);
        }
        
        if (memoization.find(hash) != memoization.end()) {
            return memoization[hash];
        }
        
        for (int i = 0; i < temp.size(); ++i) {
            mapCount[temp[i]]--;
            if (mapCount[temp[i]] == 0) {
                mapCount.erase(temp[i]);
            }
            ret += myDFS (mapCount);
            mapCount[temp[i]]++;
        }
        
        memoization[hash] = ret;
        
        return ret;
    }
    
private:
    unordered_map<double, long long> memoization;
};