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


// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if(!node) return node;

        // write your code here
        map <UndirectedGraphNode*, UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> Q;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        Q.push(node);
        visited[node] = copy;
        while(!Q.empty()){
            UndirectedGraphNode* curr = Q.front();
            Q.pop();
            
            //看鄰居是否visited 
            //在 visited 裡面嗎？
            
            //vector<UndirectedGraphNode *> neighbors;
            for(auto val:curr->neighbors){
                //如果找不到:1.加進去visited 2. 放進queue
                if (visited.find(val) == visited.end())
                {
                    visited[val] = new UndirectedGraphNode(val->label);
                    Q.push(val);
                }
                
                visited[curr]->neighbors.push_back(visited[val]);
                
            }
             
        }
        return copy; 
    }
};
