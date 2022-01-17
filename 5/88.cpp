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
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        if (!root) return nullptr;

        if (root == A || root == B) return root;

        TreeNode *left_ancestor = lowestCommonAncestor(root->left, A, B);
        TreeNode *right_ancestor = lowestCommonAncestor(root->right, A, B);

        if (left_ancestor && right_ancestor) return root;

        if (left_ancestor) return left_ancestor;

        if (right_ancestor) return right_ancestor;

        return nullptr;
    }
};
