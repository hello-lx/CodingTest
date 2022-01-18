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
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        dfs(root);

        return data;
    }

    void dfs(TreeNode *root){
        if(!root) return;

        data.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

private:
    vector<int> data;
};
