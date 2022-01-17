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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        int ans = -INT_MAX - 1;
        (void)divideConquer(root, ans);

        return ans == -INT_MAX - 1 ? 0 : ans;
    }

    int divideConquer(TreeNode * root, int &ans) {
        if (!root) {
            return 0;
        }

        int left = divideConquer(root->left, ans);
        int right = divideConquer(root->right, ans);
        
        ans = max(ans, left + right + root->val);
        return max(0, max(left, right) + root->val);
    }

};
