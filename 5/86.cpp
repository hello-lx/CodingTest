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


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
    void dfs(TreeNode * root)
    {
        if(!root) return;
        dfs(root->left);
        nodes.push_back(root);
        dfs(root->right);
    }

    BSTIterator(TreeNode * root) {
        // do intialization if necessary
        dfs(root);
        index = 0;
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        if(index < nodes.size())
            return true;
        return false;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        if(index < nodes.size())
            return nodes[index++];
        
        return nullptr;
    }

private:
    vector<TreeNode*> nodes;
    int index;
};

