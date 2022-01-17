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
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */

    // write your code here
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr || p == nullptr) return nullptr;
        if (p->val >= root->val) return inorderSuccessor(root->right, p);
        TreeNode* left = inorderSuccessor(root->left, p);
        return left == nullptr ? root : left;
    }
};

