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
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    
    bool midtraveral(TreeNode * root, int& k, int& res)
    {
        if (!root)
            return false;
        
        if (midtraveral(root->left, k, res))
            return true;

        if (--k == 0)
        {
            res = root->val;
            return true;
        }
        
        if (midtraveral(root->right, k, res))
            return true;

        return false;
    }

    int kthSmallest(TreeNode * root, int k) {
        if (!root)
            return 0;
        int res = 0;
        midtraveral(root, k, res);
        return res;
    }
};