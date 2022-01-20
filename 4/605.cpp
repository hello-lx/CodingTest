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

#define INT_MIN -99999999999
#define INT_MAX 99999999999


// 拓扑排序模板的简单解法，用两个哈希表分别记录图的节点构造和入度, tp数组记录输出的拓扑序。最后tp和org比较值，相同则存在解

class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) 
    {
        unordered_map<int, unordered_set<int>> g;
        unordered_map<int, int> indegree;
        queue<int> Q;
        vector<int> tp;

        for (auto& s : seqs)
        {
            for (int i = 0; i < s.size(); ++i) 
            {
                g[s[i]];
                if (i + 1 < s.size()){
                    if (g[s[i]].count(s[i+1]) == 0)
                        indegree[s[i + 1]] += 1;
                    g[s[i]].insert(s[i + 1]);
                }
            }
        }
        
        if (g.size() != org.size())
            return false;
            
        if (g.size() == 0 && org.size() == 0)
            return true;

        for (auto p : g)
        {
            if (indegree[p.first] == 0) {
                Q.push(p.first);
                tp.push_back(p.first);
            }
        }
 
        if (tp.size() != 1) 
            return false;

        while (!Q.empty()) {
            if(Q.size() != 1)
                return false;
             
            int curr = Q.front();
            Q.pop();
 
            int count = 0;
            for (auto next : g[curr]) {
                indegree[next] -= 1;
                if (indegree[next] == 0) {
                    count += 1;
                    Q.push(next);
                    tp.push_back(next);
                }
            }
        }
 
        return tp == org;
    }
};
