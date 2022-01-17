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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */

    void dfs(TreeNode *root, int &depth, int high)
    {
        if(!root) return;

        dfs(root->left, depth, high+1);
        dfs(root->right, depth, high+1);

        if(!root->left && !root->right)
        {
            if(high > depth)
            {
                depth = high;
            }
        }
    }

    int maxDepth(TreeNode * root) {
        // write your code here
        if(!root)   return 0;

        int depth=INT_MIN, high=1;
        dfs(root, depth, high);

        return depth;
    }
};
