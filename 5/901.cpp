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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
       // write your code here
        int closest = root->val;
        while (root) {
            if (abs(closest - target) >= abs(root->val - target)) {
                closest = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return closest;            // write your code here
    }
};
