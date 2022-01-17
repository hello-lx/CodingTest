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
     * @return: True if the binary tree is BST, or false
     */

    void dfs(TreeNode *root, vector<int> &res){
        if(!root) return;

        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }

    bool isValidBST(TreeNode * root) {
        if(!root) return true;

        vector<int> res;
        dfs(root, res);

        for(int i=0; i<res.size()-1; i++)
        {
            if(res[i] >= res[i+1])
                return false;
        }

        return true;
    }

};