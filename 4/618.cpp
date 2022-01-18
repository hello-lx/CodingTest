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


// Definition for Undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) 
    {
        // write your code here
        if (node == nullptr) {
            return nullptr;
        }
        if (values[node] == target) {
            return node;
        }
        unordered_set<UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> q;
        visited.insert(node);
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* first = q.front();
            q.pop();
            //node->neighbors = vector<node*>
            vector<UndirectedGraphNode*> temp = first->neighbors;
            for (int i = 0; i < temp.size() ; i++) {
                if (visited.count(temp[i]) != 0) {
                    continue;
                }
                if (values[temp[i]] == target) {
                    return temp[i];
                }
                q.push(temp[i]);
                visited.insert(temp[i]);
            }
        }

        return nullptr;
    }
};
