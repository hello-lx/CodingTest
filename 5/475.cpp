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
     * @param root: the root of binary tree.
     * @return: An integer
     */
    int dfs(TreeNode *root)
    {
        if(!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);
        int sumMaxTree = max(l, r) + root->val;
        
        return max(sumMaxTree, root->val);
    }

    int maxPathSum2(TreeNode * root) {
        // write your code here
        return dfs(root);
    }
};

