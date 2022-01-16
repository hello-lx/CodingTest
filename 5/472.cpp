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

class ParentTreeNode {
public:
    int val;
    ParentTreeNode *parent, *left, *right;
};


class Solution {
public:
    void dfs(ParentTreeNode * root, int target, vector<int> path, unordered_set<ParentTreeNode*> visit, vector<vector<int>>& res)
    {
        if (!root || visit.count(root))
            return;
        visit.insert(root);
        path.push_back(root->val);
        target -= root->val;
        if (!target)
        {
            res.push_back(path);
        }

        dfs(root->left, target, path, visit, res);
        dfs(root->right, target, path, visit, res);
        dfs(root->parent, target, path, visit, res);
        path.pop_back();
        visit.erase(root);
    }
    
    vector<vector<int>> binaryTreePathSum3(ParentTreeNode * root, int target) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<ParentTreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            
            dfs(cur, target, {}, {}, res);

            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }

        return res;
    }
};
