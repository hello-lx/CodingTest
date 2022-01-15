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

class TreeNode {
public:
    int val;     
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
public:
    int dfs(TreeNode * root, pair<int, TreeNode *>& res)
    {
        if (!root)
            return 0;

        int leftVal  = dfs(root->left, res);
        int rightVal = dfs(root->right, res);
        
        int sum = leftVal + rightVal + root->val;
        if (sum < res.first)
        {
            res.first = sum;
            res.second = root;
        }

        return sum;
    }
    
    TreeNode * findSubtree(TreeNode * root) {
        if (!root)
            return nullptr;
        pair<int, TreeNode *> res(0x3f3f3f3f, nullptr);
        dfs(root, res);
        return res.second;
    }
};
