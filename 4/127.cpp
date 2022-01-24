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


struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        if(graph.empty()) return graph;
        
        unordered_map<DirectedGraphNode*, int> indegrees;
        for(auto g: graph)
        {
            if(!indegrees.count(g))
                indegrees[g] = 0;
            for(auto n: g->neighbors)
                indegrees[n]++;
        }

        queue<DirectedGraphNode*> Q;
        for(auto node: indegrees)
        {
            if(node.second == 0)
                Q.push(node.first);
        }

        vector<DirectedGraphNode*> res;
        while(!Q.empty())
        {
            DirectedGraphNode* cur = Q.front();
            Q.pop();
            res.push_back(cur);
            
            for(auto n: cur->neighbors)
            {
                if(--indegrees[n] == 0)
                    Q.push(n);
            }
        }

        return res;
    }
};