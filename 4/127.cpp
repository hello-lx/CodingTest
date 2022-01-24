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
        vector<DirectedGraphNode*> order;

        if (graph.empty()) return order;

        unordered_map<DirectedGraphNode*, int> indegrees = compute_indegree(graph);

        queue<DirectedGraphNode*> q;
        for (auto node : indegrees) {
            if (node.second == 0) {
                q.push(node.first);
            }
        }

        while (!q.empty()) {
            DirectedGraphNode *current = q.front();
            q.pop();
            order.push_back(current);

            for (auto neighbor : current->neighbors) {
                if (--indegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return order;
    }

    unordered_map<DirectedGraphNode*, int> compute_indegree(vector<DirectedGraphNode*> graph) {
        unordered_map<DirectedGraphNode*, int> indegrees;

        for (auto node : graph) {
            if (!indegrees.count(node)) indegrees[node] = 0;

            for (auto neighbor : node->neighbors) {
                indegrees[neighbor]++;
            }
        }

        return indegrees;
    }
};