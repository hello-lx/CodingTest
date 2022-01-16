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

/*  前序遍历-非递归（用Stack）实现，入栈顺序（根->右->左）  */

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        if (!root) return;

        stack<TreeNode*> s;

        s.push(root);
        while (!s.empty()) {
            TreeNode *current = s.top();
            s.pop();

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);

            current->left = nullptr;
            if (!s.empty()) {
                current->right = s.top();
            } else {
                current->right = nullptr;
            }
        }
    }
};
