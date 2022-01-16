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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */

    vector<string> binaryTreePaths(TreeNode * root) {
        if (root == NULL) {
            return vector<string>();
        }
        if (root->left == NULL && root->right == NULL) {
            string x = to_string(root->val);
            return vector<string>{x};
        }
        
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        
        vector<string> ret;
        for (auto& s : left) {
            ret.push_back(to_string(root->val) + "->" + s);
        }
        for (auto& s : right) {
            ret.push_back(to_string(root->val) + "->" + s);
        }
        return ret;    
    }
};
