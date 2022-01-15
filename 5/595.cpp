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
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode* lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) 
    {
        TreeNode* ans = nullptr;
        dfs(root, A, B, ans);
        return ans;
    }
    
    bool dfs(TreeNode* curr, TreeNode* p, TreeNode *q, TreeNode*& ans) 
    {
        if(!curr) return false;
        int left = dfs(curr->left, p, q, ans) ? 1 : 0;
        int right = dfs(curr->right, p, q, ans) ? 1 : 0;
        int mid = (curr == p || curr == q) ? 1 : 0;
        int sum = left + right + mid;
        if (sum > 1) ans = curr;
        return (sum > 0);
    }
};
