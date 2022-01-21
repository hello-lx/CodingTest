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


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) 
    {
        if (graph.empty() || !s || !t) {
            return -1;
        }
        
        queue<UndirectedGraphNode*> q;
        unordered_set<UndirectedGraphNode*> visited;
        
        q.push(s);
        visited.insert(s);
        int len = 0;
        while (!q.empty()) {
            len++;
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                UndirectedGraphNode* cur = q.front();
                q.pop();
                if (cur == t) {
                    return len - 1;
                }
                for (auto next : cur->neighbors) {
                    if (visited.count(next)) {
                        continue;
                    }
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        return -1;
    }
};

