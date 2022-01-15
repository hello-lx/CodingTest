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
    TreeNode *findSubtree2(TreeNode* root) {
        if (!root) return root;
        dfs(root);
        return ans;
    }
    
    pair<double, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int num = l.second + r.second + 1;
        double average = ((double)root->val + (l.first * l.second) + (r.first * r.second)) / num;
        if (average > maxAve) 
        {
            maxAve = average;
            ans = root;
        }
        return {average, num};
    }

private:
    double maxAve = INT_MIN;
    TreeNode* ans;
};