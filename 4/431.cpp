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


//BFS 题解：
class Solution {
public:

    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        // write your code here
        unordered_set<int> visited;
        vector<vector<int>> ans;
        
        for(int i=0; i<nodes.size(); i++)
        {
            vector<int> res;
            BFS(nodes[i], res, visited);
            sort(res.begin(), res.end());
            if(!res.empty())
                ans.push_back(res);
        }

        return ans;
    }

    void BFS(UndirectedGraphNode* node, vector<int> &res, unordered_set<int> &visited){
        if(visited.find(node->label) != visited.end())
            return;
        
        queue<UndirectedGraphNode*> Q;
        Q.push(node);
        visited.insert(node->label);
        while(!Q.empty())
        {
            UndirectedGraphNode* cur = Q.front();
            Q.pop();
            res.push_back(cur->label);
            
            for(int i=0; i<cur->neighbors.size(); i++)
            {
                UndirectedGraphNode* n = cur->neighbors[i];
                if(visited.find(n->label) != visited.end())
                    continue;
                visited.insert(n->label);
                Q.push(n);
            }
        }
    }
};




//DFS 题解：
class Solution2 {
public:

    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        
        vector<vector<int>> ans;
        
        unordered_set<UndirectedGraphNode*> visited;
        
        for (int i = 0; i < nodes.size(); ++i) {
            if (visited.find(nodes[i]) != visited.end()) {
                continue;
            }
            vector<int> target;
            myDFS(nodes[i], target, visited);
            sort(target.begin(), target.end());
            ans.push_back(target);
        }
        
        return ans;
    }
    
    void myDFS (UndirectedGraphNode* node,
                vector<int> &target,
                unordered_set<UndirectedGraphNode*> &visited) 
    {
        visited.insert(node);
        target.push_back(node->label);
        
        for (int i = 0; i < node->neighbors.size(); ++i) {
            UndirectedGraphNode *curr = node->neighbors[i];
            if (visited.find(curr) != visited.end()) {
                continue;
            }
            myDFS(curr, target, visited);
        }
    }
};